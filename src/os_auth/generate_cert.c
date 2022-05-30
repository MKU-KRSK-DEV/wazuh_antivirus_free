/*
 * Wazuh Certificate creation.
 *
 * Copyright (C) 2015, Wazuh Inc.
 * May 16, 2021.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */

#include "generate_cert.h"

EVP_PKEY* generate_key(int bits) {
    EVP_PKEY* key = EVP_PKEY_new();
    BIGNUM* bn = BN_new();
    RSA* rsa = RSA_new(); // This structure is free'd after EVP_PKEY_assign_RSA.

    if(key == NULL) {
        printf("Cannot create EVP_PKEY structure.\n");
        goto error;
    }

    if (bn == NULL) {
        printf("Cannot create BN structure.\n");
        goto error;
    }

    if (rsa == NULL) {
        printf("Cannot create RSA structure.\n");
        goto error;
    }

    BN_set_word(bn, RSA_F4);
    RSA_generate_key_ex(rsa, bits, bn, NULL);

    if(!EVP_PKEY_assign_RSA(key, rsa)) {
        printf("Cannot generate RSA key.\n");
        goto error;
    }

    BN_free(bn);
    return key;

error:
    RSA_free(rsa);
    BN_free(bn);
    EVP_PKEY_free(key);

    return NULL;
}


/**
 * @brief Generates a self-signed X509 certificate.
 *
 * @param key Key that will be used to sign the certificate.
 * @return 1 on failure 0 on success.
 */
int generate_cert(unsigned long days, unsigned long bits, const char *key_path, const char *cert_path) {
    X509* cert = X509_new();
    EVP_PKEY* key = NULL;
    ASN1_INTEGER* serial_number = ASN1_INTEGER_new();
    X509_NAME* name = NULL;
    X509V3_CTX ctx;

    if(cert == NULL) {
        printf("Cannot generate certificate\n");
        goto error;
    }

    if (serial_number == NULL) {
        printf("Cannot allocate serial number\n");
        goto error;
    }

    // Assign a random serial number to the certificate
    if (rand_serial(serial_number) == 1) {
        printf("Cannot generate serial number.\n");
        goto error;
    }

    key = generate_key(bits);
    X509_set_version(cert, 2);
    X509_set_serialNumber(cert, serial_number);
    X509_gmtime_adj(X509_get_notBefore(cert), 0);
    X509_gmtime_adj(X509_get_notAfter(cert), days * 86400UL);

    X509_set_pubkey(cert, key);

    name = X509_get_subject_name(cert);

    X509_NAME_add_entry_by_txt(name, "C",  MBSTRING_ASC, (unsigned char *)  "US"         , -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "ST",  MBSTRING_ASC, (unsigned char *) "California" , -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC, (unsigned char *)  "Wazuh"      , -1, -1, 0);

    X509_set_issuer_name(cert, name);
    X509V3_set_ctx_nodb(&ctx);
    X509V3_set_ctx(&ctx, cert, cert, NULL, NULL, 0);

    add_x509_ext(cert, &ctx, NID_subject_key_identifier, "hash");
    add_x509_ext(cert, &ctx, NID_authority_key_identifier, "keyid");
    add_x509_ext(cert, &ctx, NID_basic_constraints, "critical,CA:TRUE");

    if(!X509_sign(cert, key, EVP_sha256())) {
        printf("Error signing certificate.\n");
        goto error;
    }

    dump_key_cert(key, cert, key_path, cert_path);
    EVP_PKEY_free(key);
    ASN1_INTEGER_free(serial_number);

    return 0;

error:

    X509_free(cert);
    ASN1_INTEGER_free(serial_number);
    return 1;


}

void add_x509_ext(X509* cert, X509V3_CTX *ctx, int ext_nid, const char *value) {
    X509_EXTENSION *ex = X509V3_EXT_conf_nid(NULL, ctx, ext_nid, value);

    X509_add_ext(cert, ex, -1);

    X509_EXTENSION_free(ex);
}

int dump_key_cert(EVP_PKEY* key, X509* x509, const char* key_name, const char* cert_name) {
    FILE* key_file = fopen(key_name, "wb");

    if(!key_file)
    {
        printf("Cannot open %s\n ", key_name);
        return 1;
    }

    if(!PEM_write_PrivateKey(key_file, key, NULL, NULL, 0, NULL, NULL))
    {
        printf("Cannot dump private key.\n");
        fclose(key_file);

        return 1;
    }

    FILE* x509_file = fopen(cert_name, "wb");
    if(!x509_file)
    {
        printf("Cannot open %s.\n", cert_name);
        return 1;
    }

    if(!PEM_write_X509(x509_file, x509))
    {
        printf("Cannot dump certificate.\n");
        fclose(x509_file);

        return 1;
    }

    fclose(key_file);
    fclose(x509_file);

    return 0;
}


int rand_serial(ASN1_INTEGER *sn) {
    BIGNUM* bn = BN_new();

    if (sn == NULL) {
        return 1;
    }

    if (bn == NULL) {
        return 1;
    }

    /*
    * The 159 constant is defined in openssl/apps/apps.h (SERIAL_RAND_BITS)
    * IETF RFC 5280 says serial number must be <= 20 bytes. Use 159 bits
    * so that the first bit will never be one, so that the DER encoding
    * rules won't force a leading octet.
    */
    if (!BN_rand(bn, 159, BN_RAND_TOP_ANY, BN_RAND_BOTTOM_ANY)) {
        return 1;
    }

    if (!BN_to_ASN1_INTEGER(bn, sn)) {
        BN_free(bn);
        return 1;
    }

    BN_free(bn);

    return 0;
}
