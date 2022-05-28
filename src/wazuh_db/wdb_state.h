/*
 * Copyright (C) 2015, Wazuh Inc.
 * May 03, 2022
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */

#ifndef STATEWDB_H
#define STATEWDB_H

#include <stdint.h>
#include <sys/time.h>
#include "wdb.h"

#define VERSION 1

/* Status structures */

typedef struct _agent_syscheck_t {
    uint64_t syscheck_queries;
    uint64_t fim_file_queries;
    uint64_t fim_registry_queries;
    struct timeval syscheck_time;
    struct timeval fim_file_time;
    struct timeval fim_registry_time;
} agent_syscheck_t;

typedef struct _agent_syscollector_t {
    uint64_t syscollector_processes_queries;
    uint64_t syscollector_packages_queries;
    uint64_t syscollector_hotfixes_queries;
    uint64_t syscollector_ports_queries;
    uint64_t syscollector_network_protocol_queries;
    uint64_t syscollector_network_address_queries;
    uint64_t syscollector_network_iface_queries;
    uint64_t syscollector_hwinfo_queries;
    uint64_t syscollector_osinfo_queries;
    uint64_t process_queries;
    uint64_t package_queries;
    uint64_t hotfix_queries;
    uint64_t port_queries;
    uint64_t netproto_queries;
    uint64_t netaddr_queries;
    uint64_t netinfo_queries;
    uint64_t hardware_queries;
    uint64_t osinfo_queries;
    struct timeval syscollector_processes_time;
    struct timeval syscollector_packages_time;
    struct timeval syscollector_hotfixes_time;
    struct timeval syscollector_ports_time;
    struct timeval syscollector_network_protocol_time;
    struct timeval syscollector_network_address_time;
    struct timeval syscollector_network_iface_time;
    struct timeval syscollector_hwinfo_time;
    struct timeval syscollector_osinfo_time;
    struct timeval process_time;
    struct timeval package_time;
    struct timeval hotfix_time;
    struct timeval port_time;
    struct timeval netproto_time;
    struct timeval netaddr_time;
    struct timeval netinfo_time;
    struct timeval hardware_time;
    struct timeval osinfo_time;
} agent_syscollector_t;

typedef struct _agent_breakdown_t {
    uint64_t sql_queries;
    uint64_t remove_queries;
    uint64_t begin_queries;
    uint64_t commit_queries;
    uint64_t close_queries;
    uint64_t rootcheck_queries;
    uint64_t sca_queries;
    uint64_t ciscat_queries;
    uint64_t vulnerability_detector_queries;
    uint64_t dbsync_queries;
    uint64_t unknown_queries;
    struct timeval sql_time;
    struct timeval remove_time;
    struct timeval begin_time;
    struct timeval commit_time;
    struct timeval close_time;
    struct timeval rootcheck_time;
    struct timeval sca_time;
    struct timeval ciscat_time;
    struct timeval vulnerability_detector_time;
    struct timeval dbsync_time;
    agent_syscheck_t syscheck;
    agent_syscollector_t syscollector;
} agent_breakdown_t;

typedef struct _global_agent_t {
    uint64_t insert_agent_queries;
    uint64_t update_agent_data_queries;
    uint64_t update_agent_name_queries;
    uint64_t update_keepalive_queries;
    uint64_t update_connection_status_queries;
    uint64_t reset_agents_connection_queries;
    uint64_t sync_agent_info_set_queries;
    uint64_t delete_agent_queries;
    uint64_t select_agent_name_queries;
    uint64_t select_agent_group_queries;
    uint64_t select_keepalive_queries;
    uint64_t find_agent_queries;
    uint64_t get_agent_info_queries;
    uint64_t get_all_agents_queries;
    uint64_t get_agents_by_connection_status_queries;
    uint64_t disconnect_agents_queries;
    uint64_t sync_agent_info_get_queries;
    uint64_t sync_agent_groups_get_queries;
    uint64_t set_agent_groups_queries;
    uint64_t get_groups_integrity_queries;
    struct timeval insert_agent_time;
    struct timeval update_agent_data_time;
    struct timeval update_agent_name_time;
    struct timeval update_keepalive_time;
    struct timeval update_connection_status_time;
    struct timeval reset_agents_connection_time;
    struct timeval sync_agent_info_set_time;
    struct timeval delete_agent_time;
    struct timeval select_agent_name_time;
    struct timeval select_agent_group_time;
    struct timeval select_keepalive_time;
    struct timeval find_agent_time;
    struct timeval get_agent_info_time;
    struct timeval get_all_agents_time;
    struct timeval get_agents_by_connection_status_time;
    struct timeval disconnect_agents_time;
    struct timeval sync_agent_info_get_time;
    struct timeval sync_agent_groups_get_time;
    struct timeval set_agent_groups_time;
    struct timeval get_groups_integrity_time;
} global_agent_t;

typedef struct _global_group_t {
    uint64_t insert_agent_group_queries;
    uint64_t delete_group_queries;
    uint64_t select_groups_queries;
    uint64_t find_group_queries;
    struct timeval insert_agent_group_time;
    struct timeval delete_group_time;
    struct timeval select_groups_time;
    struct timeval find_group_time;
} global_group_t;

typedef struct _global_belongs_t {
    uint64_t select_group_belong_queries;
    uint64_t delete_agent_belong_queries;
    uint64_t get_group_agent_queries;
    struct timeval select_group_belong_time;
    struct timeval delete_agent_belong_time;
    struct timeval get_group_agent_time;
} global_belongs_t;

typedef struct _global_labels_t {
    uint64_t set_labels_queries;
    uint64_t get_labels_queries;
    struct timeval set_labels_time;
    struct timeval get_labels_time;
} global_labels_t;

typedef struct _global_breakdown_t {
    uint64_t sql_queries;
    uint64_t backup_queries;
    uint64_t unknown_queries;
    struct timeval sql_time;
    struct timeval backup_time;
    global_agent_t agent;
    global_group_t group;
    global_belongs_t belongs;
    global_labels_t labels;
} global_breakdown_t;

typedef struct _task_upgrade_t {
    uint64_t upgrade_queries;
    uint64_t upgrade_custom_queries;
    uint64_t upgrade_get_status_queries;
    uint64_t upgrade_update_status_queries;
    uint64_t upgrade_result_queries;
    uint64_t upgrade_cancel_tasks_queries;
    struct timeval upgrade_time;
    struct timeval upgrade_custom_time;
    struct timeval upgrade_get_status_time;
    struct timeval upgrade_update_status_time;
    struct timeval upgrade_result_time;
    struct timeval upgrade_cancel_tasks_time;
} task_upgrade_t;

typedef struct _task_breakdown_t {
    uint64_t sql_queries;
    uint64_t set_timeout_queries;
    uint64_t delete_old_queries;
    uint64_t unknown_queries;
    struct timeval sql_time;
    struct timeval set_timeout_time;
    struct timeval delete_old_time;
    task_upgrade_t upgrade;
} task_breakdown_t;

typedef struct _mitre_breakdown_t {
    uint64_t sql_queries;
    uint64_t unknown_queries;
    struct timeval sql_time;
} mitre_breakdown_t;

typedef struct _wazuhdb_breakdown_t {
    uint64_t get_config_queries;
    uint64_t remove_queries;
    uint64_t unknown_queries;
    struct timeval get_config_time;
    struct timeval remove_time;
} wazuhdb_breakdown_t;

typedef struct _queries_breakdown_t {
    uint64_t wazuhdb_queries;
    uint64_t agent_queries;
    uint64_t global_queries;
    uint64_t task_queries;
    uint64_t mitre_queries;
    uint64_t unknown_queries;
    wazuhdb_breakdown_t wazuhdb_breakdown;
    agent_breakdown_t agent_breakdown;
    global_breakdown_t global_breakdown;
    task_breakdown_t task_breakdown;
    mitre_breakdown_t mitre_breakdown;
} queries_breakdown_t;

typedef struct _db_stats_t {
    uint64_t queries_total;
    queries_breakdown_t queries_breakdown;
} db_stats_t;

/* Status functions */

/**
 * @brief Increment total queries counter
 *
 */
void w_inc_queries_total();

/**
 * @brief Increment total wazuhdb queries counter
 *
 */
void w_inc_wazuhdb();

/**
 * @brief Increment get-config wazuhdb queries counter
 *
 */
void w_inc_wazuhdb_get_config();

/**
 * @brief Increment remove wazuhdb queries counter
 *
 */
void w_inc_wazuhdb_remove();

/**
 * @brief Increment unknown wazuhdb queries counter
 *
 */
void w_inc_wazuhdb_unknown();

/**
 * @brief Increment total agent queries counter
 *
 */
void w_inc_agent();

/**
 * @brief Increment sql agent queries counter
 *
 */
void w_inc_agent_sql();

/**
 * @brief Increment remove agent queries counter
 *
 */
void w_inc_agent_remove();

/**
 * @brief Increment begin agent queries counter
 *
 */
void w_inc_agent_begin();

/**
 * @brief Increment commit agent queries counter
 *
 */
void w_inc_agent_commit();

/**
 * @brief Increment close agent queries counter
 *
 */
void w_inc_agent_close();

/**
 * @brief Increment rootcheck agent queries counter
 *
 */
void w_inc_agent_rootcheck();

/**
 * @brief Increment sca agent queries counter
 *
 */
void w_inc_agent_sca();

/**
 * @brief Increment ciscat agent queries counter
 *
 */
void w_inc_agent_ciscat();

/**
 * @brief Increment vulnerability detector agent queries counter
 *
 */
void w_inc_agent_vul_detector();

/**
 * @brief Increment dbsync agent queries counter
 *
 */
void w_inc_agent_dbsync();

/**
 * @brief Increment unknown agent queries counter
 *
 */
void w_inc_agent_unknown();

/**
 * @brief Increment syscheck agent queries counter
 *
 */
void w_inc_agent_syscheck();

/**
 * @brief Increment fim file agent queries counter
 *
 */
void w_inc_agent_fim_file();

/**
 * @brief Increment fim registry agent queries counter
 *
 */
void w_inc_agent_fim_registry();

/**
 * @brief Increment syscollector processes agent queries counter
 *
 */
void w_inc_agent_syscollector_processes();

/**
 * @brief Increment syscollector packages agent queries counter
 *
 */
void w_inc_agent_syscollector_packages();

/**
 * @brief Increment syscollector hotfixes agent queries counter
 *
 */
void w_inc_agent_syscollector_hotfixes();

/**
 * @brief Increment syscollector ports agent queries counter
 *
 */
void w_inc_agent_syscollector_ports();

/**
 * @brief Increment syscollector network protocol agent queries counter
 *
 */
void w_inc_agent_syscollector_network_protocol();

/**
 * @brief Increment syscollector network address agent queries counter
 *
 */
void w_inc_agent_syscollector_network_address();

/**
 * @brief Increment syscollector network interface agent queries counter
 *
 */
void w_inc_agent_syscollector_network_iface();

/**
 * @brief Increment syscollector hardware information agent queries counter
 *
 */
void w_inc_agent_syscollector_hwinfo();


/**
 * @brief Increment syscollector OS information agent queries counter
 *
 */
void w_inc_agent_syscollector_osinfo();

/**
 * @brief Increment deprecated syscollector processes agent queries counter
 *
 */
void w_inc_agent_syscollector_deprecated_process();

/**
 * @brief Increment deprecated syscollector packages agent queries counter
 *
 */
void w_inc_agent_syscollector_deprecated_packages();

/**
 * @brief Increment deprecated syscollector hotfixes agent queries counter
 *
 */
void w_inc_agent_syscollector_deprecated_hotfixes();

/**
 * @brief Increment deprecated syscollector ports agent queries counter
 *
 */
void w_inc_agent_syscollector_deprecated_ports();

/**
 * @brief Increment deprecated syscollector network protocol agent queries counter
 *
 */
void w_inc_agent_syscollector_deprecated_network_protocol();

/**
 * @brief Increment deprecated syscollector network address agent queries counter
 *
 */
void w_inc_agent_syscollector_deprecated_network_address();

/**
 * @brief Increment deprecated syscollector network information agent queries counter
 *
 */
void w_inc_agent_syscollector_deprecated_network_info();

/**
 * @brief Increment deprecated syscollector hardware agent queries counter
 *
 */
void w_inc_agent_syscollector_deprecated_hardware();

/**
 * @brief Increment deprecated syscollector OS information agent queries counter
 *
 */
void w_inc_agent_syscollector_deprecated_osinfo();

/**
 * @brief Increment total global queries counter
 *
 */
void w_inc_global();

/**
 * @brief Increment sql global queries counter
 *
 */
void w_inc_global_sql();

/**
 * @brief Increment backup global queries counter
 *
 */
void w_inc_global_backup();

/**
 * @brief Increment unknown global queries counter
 *
 */
void w_inc_global_unknown();

/**
 * @brief Increment insert-agent global agent queries counter
 *
 */
void w_inc_global_agent_insert_agent();

/**
 * @brief Increment update-agent-data global agent queries counter
 *
 */
void w_inc_global_agent_update_agent_data();

void w_inc_global_agent_update_agent_name();

void w_inc_global_agent_update_keepalive();

void w_inc_global_agent_update_connection_status();

void w_inc_global_agent_reset_agents_connection();

void w_inc_global_agent_sync_agent_info_set();

void w_inc_global_agent_delete_agent();

void w_inc_global_agent_select_agent_name();

void w_inc_global_agent_select_agent_group();

void w_inc_global_agent_select_keepalive();

void w_inc_global_agent_find_agent();

void w_inc_global_agent_get_agent_info();

void w_inc_global_agent_get_all_agents();

void w_inc_global_agent_get_agents_by_connection_status();

void w_inc_global_agent_disconnect_agents();

void w_inc_global_agent_sync_agent_info_get();

void w_inc_global_agent_sync_agent_groups_get();

void w_inc_global_agent_set_agent_groups();

void w_inc_global_agent_get_groups_integrity();

void w_inc_global_group_insert_agent_group();

void w_inc_global_group_delete_group();

void w_inc_global_group_select_groups();

void w_inc_global_group_find_group();

void w_inc_global_belongs_select_group_belong();

void w_inc_global_belongs_delete_agent_belong();

void w_inc_global_belongs_get_group_agent();

void w_inc_global_labels_set_labels();

void w_inc_global_labels_get_labels();

void w_inc_task();

void w_inc_task_sql();

void w_inc_task_set_timeout();

void w_inc_task_delete_old();

void w_inc_task_unknown();

void w_inc_task_upgrade();

void w_inc_task_upgrade_custom();

void w_inc_task_upgrade_get_status();

void w_inc_task_upgrade_update_status();

void w_inc_task_upgrade_result();

void w_inc_task_upgrade_cancel_tasks();

void w_inc_mitre();

void w_inc_mitre_sql();

void w_inc_mitre_unknown();

void w_inc_unknown();

void w_inc_agent_syscheck_time(struct timeval time);

void w_inc_agent_fim_file_time(struct timeval time);

void w_inc_agent_fim_registry_time(struct timeval time);

void w_inc_agent_syscollector_times(struct timeval time, wdb_component_t type);

void w_inc_agent_syscollector_deprecated_process_time(struct timeval time);

void w_inc_agent_syscollector_deprecated_hotfixes_time(struct timeval time);

void w_inc_agent_syscollector_deprecated_packages_time(struct timeval time);

void w_inc_agent_syscollector_deprecated_ports_time(struct timeval time);

void w_inc_agent_syscollector_deprecated_hardware_time(struct timeval time);

void w_inc_agent_syscollector_deprecated_osinfo_time(struct timeval time);

void w_inc_agent_syscollector_deprecated_network_address_time(struct timeval time);

void w_inc_agent_syscollector_deprecated_network_protocol_time(struct timeval time);

void w_inc_agent_syscollector_deprecated_network_info_time(struct timeval time);

void w_inc_agent_sql_time(struct timeval time);

void w_inc_agent_remove_time(struct timeval time);

void w_inc_agent_begin_time(struct timeval time);

void w_inc_agent_commit_time(struct timeval time);

void w_inc_agent_close_time(struct timeval time);

void w_inc_agent_rootcheck_time(struct timeval time);

void w_inc_agent_ciscat_time(struct timeval time);

void w_inc_agent_dbsync_time(struct timeval time);

void w_inc_agent_sca_time(struct timeval time);

void w_inc_agent_vul_detector_time(struct timeval time);

void w_inc_mitre_sql_time(struct timeval time);

void w_inc_global_agent_insert_agent_time(struct timeval time);

void w_inc_global_agent_update_agent_data_time(struct timeval time);

void w_inc_global_agent_update_agent_name_time(struct timeval time);

void w_inc_global_agent_update_keepalive_time(struct timeval time);

void w_inc_global_agent_update_connection_status_time(struct timeval time);

void w_inc_global_agent_reset_agents_connection_time(struct timeval time);

void w_inc_global_agent_sync_agent_info_set_time(struct timeval time);

void w_inc_global_agent_delete_agent_time(struct timeval time);

void w_inc_global_agent_select_agent_name_time(struct timeval time);

void w_inc_global_agent_select_agent_group_time(struct timeval time);

void w_inc_global_agent_select_keepalive_time(struct timeval time);

void w_inc_global_agent_find_agent_time(struct timeval time);

void w_inc_global_agent_get_agent_info_time(struct timeval time);

void w_inc_global_agent_get_all_agents_time(struct timeval time);

void w_inc_global_agent_get_agents_by_connection_status_time(struct timeval time);

void w_inc_global_agent_disconnect_agents_time(struct timeval time);

void w_inc_global_agent_sync_agent_info_get_time(struct timeval time);

void w_inc_global_agent_sync_agent_groups_get_time(struct timeval time);

void w_inc_global_agent_set_agent_groups_time(struct timeval time);

void w_inc_global_agent_get_groups_integrity_time(struct timeval time);

void w_inc_global_group_insert_agent_group_time(struct timeval time);

void w_inc_global_group_delete_group_time(struct timeval time);

void w_inc_global_group_select_groups_time(struct timeval time);

void w_inc_global_group_find_group_time(struct timeval time);

void w_inc_global_belongs_select_group_belong_time(struct timeval time);

void w_inc_global_belongs_delete_agent_belong_time(struct timeval time);

void w_inc_global_belongs_get_group_agent_time(struct timeval time);

void w_inc_global_labels_set_labels_time(struct timeval time);

void w_inc_global_labels_get_labels_time(struct timeval time);

void w_inc_task_upgrade_time(struct timeval time);

void w_inc_task_upgrade_custom_time(struct timeval time);

void w_inc_task_upgrade_get_status_time(struct timeval time);

void w_inc_task_upgrade_update_status_time(struct timeval time);

void w_inc_task_upgrade_result_time(struct timeval time);

void w_inc_task_upgrade_cancel_tasks_time(struct timeval time);

void w_inc_task_sql_time(struct timeval time);

void w_inc_task_set_timeout_time(struct timeval time);

void w_inc_task_delete_old_time(struct timeval time);

void w_inc_global_sql_time(struct timeval time);

void w_inc_global_backup_time(struct timeval time);

void w_inc_wazuhdb_get_config_time(struct timeval time);

void w_inc_wazuhdb_remove_time(struct timeval time);

cJSON* wdb_create_state_json();

#endif
