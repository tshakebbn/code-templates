# Copyright [year] [organization]
#
# Build file for cpp apps
#

add_executable(cpp_example_app_cmake example_app.cpp)
target_link_libraries(cpp_example_app cpputils boost_log pthread boost_thread boost_system boost_log_setup boost_program_options)
install(TARGETS cpp_example_app_cmake DESTINATION bin)
