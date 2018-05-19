/** Copyright [year] [organization]
 *
 * @file exceptions.h
 *
 * @brief Example defined exceptions.
 * A more elaborate description of exceptions.
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

#ifndef CODE_TEMPLATES_CPP_CMAKE_SRC_UTILS_EXCEPTIONS_HPP_
#define CODE_TEMPLATES_CPP_CMAKE_SRC_UTILS_EXCEPTIONS_HPP_

#include <exception>
#include <stdexcept>

/**
 * Includes exceptions for CPP project.
 */
namespace cpp_exceptions {

/**
 * An example exception.
 * A more elaborate description of example exception.
 */
struct ExampleException : public std::exception {
    const char* what() const throw() {
        return "Example exception";
    }
};

}  // namespace cpp_exceptions

#endif  // CODE_TEMPLATES_CPP_CMAKE_SRC_UTILS_EXCEPTIONS_HPP_
