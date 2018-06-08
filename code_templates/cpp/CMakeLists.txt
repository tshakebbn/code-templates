# Copyright [year] [organization]
#
# Top level build file for cpp
#

cmake_minimum_required (VERSION 3.0)
project (cpp VERSION 1.0.0.0 LANGUAGES CXX)

# Configure CMAKE
set (CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/config)
set (CONFIG_FILE ${CMAKE_INSTALL_PREFIX}/etc/${PROJECT_NAME}/cpp.conf)
set (LOG_FILE ${CMAKE_INSTALL_PREFIX}/etc/${PROJECT_NAME}/cpp.log)
configure_file ("${CONFIG_DIR}/config.hpp.in" "${PROJECT_BINARY_DIR}/config.hpp")
include_directories("${PROJECT_BINARY_DIR}")
install (FILES ${CONFIG_DIR}/cpp.conf DESTINATION etc/${PROJECT_NAME} PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ GROUP_WRITE WORLD_READ WORLD_WRITE)
file (WRITE cpp.log "")
install (FILES cpp.log DESTINATION etc/${PROJECT_NAME} PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ GROUP_WRITE WORLD_READ WORLD_WRITE)

# Compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# add the utils library
add_subdirectory (src/utils)

# add the unit tests
add_subdirectory (tests)
enable_testing()
add_test (NAME test_log COMMAND test_log)
add_test (NAME test_example COMMAND test_example)

# add the executables
add_subdirectory (src)

# add the docs
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${PROJECT_BINARY_DIR}/Doxyfile)
add_custom_target (docs ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif(DOXYGEN_FOUND)
