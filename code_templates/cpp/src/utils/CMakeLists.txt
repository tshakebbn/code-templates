# Copyright [year] [organization]
#
# Build file for cpp utils library
#

add_library(cpputils STATIC log.cpp example.cpp)
target_compile_options(cpputils PRIVATE "-DBOOST_LOG_DYN_LINK")
install(TARGETS cpputils DESTINATION lib)
install(FILES exceptions.hpp log.hpp example.hpp DESTINATION include/${PROJECT_NAME})
