/** Copyright [year] [organization]
 *
 * @file log.hpp
 *
 * @brief Includes useful logging functions.
 * A more elaborate description of logging. (optional)
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

#ifndef CODE_TEMPLATES_CPP_CMAKE_SRC_UTILS_LOG_HPP_
#define CODE_TEMPLATES_CPP_CMAKE_SRC_UTILS_LOG_HPP_

#include <string>

#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>

/**
 * Includes functions for CPP logging functionality.
 */
namespace cpp_log {

namespace logging_sources = boost::log::sources;
namespace logging_trivial = boost::log::trivial;

/**
 * Log settings structure.
 * Log settings contains logger settings from config file.
 */
struct LogSettings {
    std::string level;  /**< Severity level setting. */
    std::string file;  /**< Log file name and location. */
};

/**
 * Initializes logger based on input parameters.
 * @param  log_file					log file name and location
 * @param  conf_file				conf file name and location
 * @throws std::runtime_error       error interfacing with config file
 * @throws std::invalid_argument    invalid argument in config file
 * @throws boost::exception         missing argument in config file
 */
void initialize(std::string log_file, std::string conf_file);

/**
 * Log a trace message
 * @param   message message to log
 * @param   file    file name macro
 * @param   line    line number macro
 * @throws  std::runtime_error       logger not initialized
 */
void log_trace(const char* message, const char* file, int line);

/**
 * Log a debug message
 * @param   message message to log
 * @param   file    file name macro
 * @param   line    line number macro
 * @throws  std::runtime_error       logger not initialized
 */
void log_debug(const char* message, const char* file, int line);

/**
 * Log a info message
 * @param   message message to log
 * @param   file    file name macro
 * @param   line    line number macro
 * @throws  std::runtime_error       logger not initialized
 */
void log_info(const char* message, const char* file, int line);

/**
 * Log a warning message
 * @param   message message to log
 * @param   file    file name macro
 * @param   line    line number macro
 * @throws  std::runtime_error       logger not initialized
 */
void log_warning(const char* message, const char* file, int line);

/**
 * Log a error message
 * @param   message message to log
 * @param   file    file name macro
 * @param   line    line number macro
 * @throws  std::runtime_error       logger not initialized
 */
void log_error(const char* message, const char* file, int line);

/**
 * Log a fatal message
 * @param   message message to log
 * @param   file    file name macro
 * @param   line    line number macro
 * @throws  std::runtime_error       logger not initialized
 */
void log_fatal(const char* message, const char* file, int line);

}  // namespace cpp_log

#endif  // CODE_TEMPLATES_CPP_CMAKE_SRC_UTILS_LOG_HPP_
