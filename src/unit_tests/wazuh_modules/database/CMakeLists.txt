# Copyright (C) 2022, Wazuh Inc.
#
# This program is free software; you can redistribute it
# and/or modify it under the terms of the GNU General Public
# License (version 2) as published by the FSF - Free Software
# Foundation.

#include wrappers
include(${SRC_FOLDER}/unit_tests/wrappers/wazuh/shared/shared.cmake)

list(APPEND wmdb_tests_names "test_wm_database")
list(APPEND wmdb_tests_flags "-Wl,--wrap,wdb_set_agent_groups -Wl,--wrap,opendir -Wl,--wrap,readdir -Wl,--wrap,strerror -Wl,--wrap,unlink \
                              -Wl,--wrap,closedir -Wl,--wrap,rmdir_ex -Wl,--wrap,getpid  -Wl,--wrap,w_is_single_node ${DEBUG_OP_WRAPPERS} ${STDIO_OP_WRAPPERS}")

# Add extra compiling flags
add_compile_options(-Wall)

# Compilig tests
list(LENGTH wmdb_tests_names count)
math(EXPR count "${count} - 1")
foreach(counter RANGE ${count})
    list(GET wmdb_tests_names ${counter} test_name)
    list(GET wmdb_tests_flags ${counter} test_flags)

    add_executable(${test_name} ${test_name}.c)

    target_link_libraries(
        ${test_name}
        ${WAZUHLIB}
        ${WAZUHEXT}
        ${TEST_DEPS}
    )

    if(NOT test_flags STREQUAL " ")
        target_link_libraries(
            ${test_name}
            ${test_flags}
        )
    endif()
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
