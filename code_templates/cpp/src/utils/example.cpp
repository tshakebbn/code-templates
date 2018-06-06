/** Copyright [year] [organization]
 *
 * @file example.cpp
 *
 * @brief An example implementation.
 * A more elaborate description of example implementation. (optional)
 *
 * @author [organization]
 * @author [name] (optional)
 *
 * @par [unique category]
 * [designation]
 *
 * @par Notifications
 * [distribution designation]
 * [other designations]
 */

#include "example.hpp"
#include "log.hpp"
#include "exceptions.hpp"

namespace example {

Example::Example(void) {
    cpp_log::initialize();
}

Example::~Example(void) {
}

int Example::example_function(int value, int size) {
    cpp_log::log_trace("A trace severity message", __FILE__, __LINE__);
    cpp_log::log_debug("A debug severity message", __FILE__, __LINE__);
    cpp_log::log_info("An informational severity message", __FILE__, __LINE__);
    cpp_log::log_warning("A warning severity message", __FILE__, __LINE__);
    cpp_log::log_error("An error severity message", __FILE__, __LINE__);
    cpp_log::log_fatal("A fatal severity message", __FILE__, __LINE__);

    try {
        throw cpp_exceptions::ExampleException();
    } catch(cpp_exceptions::ExampleException &exception) {
        cpp_log::log_error(exception.what(), __FILE__, __LINE__);
    }

    return 0;
}

}   // namespace example
