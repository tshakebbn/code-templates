# Copyright [year] [organization]
#
# Top level build file for cpp_cmake
#

cmake_minimum_required (VERSION 3.0)
project (cpp_cmake VERSION 0.0.0.1 LANGUAGES CXX)

# Configure CMAKE
set (CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/config)
set (CONFIG_FILE ${CMAKE_INSTALL_PREFIX}/etc/${PROJECT_NAME}/cpp_cmake.conf)
set (LOG_FILE ${CMAKE_INSTALL_PREFIX}/etc/${PROJECT_NAME}/cpp_cmake.log)
configure_file ("${CONFIG_DIR}/config.h.in" "${PROJECT_BINARY_DIR}/config.h")
include_directories("${PROJECT_BINARY_DIR}")
install (FILES ${CONFIG_DIR}/cpp_cmake.conf DESTINATION etc/${PROJECT_NAME} PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ GROUP_WRITE WORLD_READ WORLD_WRITE)
