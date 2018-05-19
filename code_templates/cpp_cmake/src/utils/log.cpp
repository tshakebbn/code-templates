/** Copyright [year] [organization]
 *
 * @file log.cpp
 *
 * @brief Implementation of useful logging functions.
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

#include <string.h>

#include <fstream>

#include <boost/program_options.hpp>
#include <boost/log/core.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include "log.h"
#include "exceptions.h"
#include "config.h"

namespace tools_log {

namespace logging = boost::log;
namespace logging_keywords = boost::log::keywords;
namespace program_options = boost::program_options;

static logging_sources::severity_logger
    <logging_trivial::severity_level> glogger;
static bool initialize_called = false;

void initialize(void) {
    if (!initialize_called) {
        LogSettings log_settings;
        program_options::variables_map variables_map;
        program_options::options_description description("Log Options");

        // setup options
        description.add_options()
            ("logger.level",
                program_options::value<std::string>
                    (&log_settings.level)->required(),
                "Logger severity level setting")
            ("logger.file",
                program_options::value<std::string>
                    (&log_settings.file)->required(),
                "Log file name and location");

        // load conf file
        std::ifstream conf_file(CONFIG_FILE,
            std::ifstream::in);
        if (!conf_file) {
            throw std::runtime_error("Missing configuration file");
        }
        program_options::store(
            program_options::parse_config_file(conf_file, description, true),
            variables_map);
        conf_file.close();
        program_options::notify(variables_map);

        // setup logger
        logging::register_simple_formatter_factory
            <logging_trivial::severity_level, char>("Severity");
        logging::add_file_log(
            log_settings.file,
            logging_keywords::auto_flush = true,
            logging_keywords::open_mode = std::ios_base::app,
            logging_keywords::format = "%TimeStamp% <%Severity%> %Message%");

        if (log_settings.level == "TRACE") {
            logging::core::get()->set_filter(
                logging_trivial::severity >= logging_trivial::trace);
        } else if (log_settings.level == "DEBUG") {
            logging::core::get()->set_filter(
                    logging_trivial::severity >= logging_trivial::debug);
        } else if (log_settings.level == "INFO") {
            logging::core::get()->set_filter(
                    logging_trivial::severity >= logging_trivial::info);
        } else if (log_settings.level == "WARNING") {
            logging::core::get()->set_filter(
                    logging_trivial::severity >= logging_trivial::warning);
        } else if (log_settings.level == "ERROR") {
            logging::core::get()->set_filter(
                    logging_trivial::severity >= logging_trivial::error);
        } else if (log_settings.level == "FATAL") {
            logging::core::get()->set_filter(
                    logging_trivial::severity >= logging_trivial::fatal);
        } else {
            throw std::invalid_argument(
                    "Invalid logfile severity setting in config file");
        }
        logging::add_common_attributes();
        initialize_called = true;
    }
}

void log_trace(const char* message, const char* file, int line) {
    BOOST_LOG_SEV(glogger, logging_trivial::trace) << "[" << basename(file)
    << ": " << line << "]: " << message;
}

void log_debug(const char* message, const char* file, int line) {
    BOOST_LOG_SEV(glogger, logging_trivial::debug) << "[" << basename(file)
    << ": " << line << "]: " << message;
}

void log_info(const char* message, const char* file, int line) {
    BOOST_LOG_SEV(glogger, logging_trivial::info) << "[" << basename(file)
    << ": " << line << "]: " << message;
}

void log_warning(const char* message, const char* file, int line) {
    BOOST_LOG_SEV(glogger, logging_trivial::warning) << "[" << basename(file)
    << ": " << line << "]: " << message;
}

void log_error(const char* message, const char* file, int line) {
    BOOST_LOG_SEV(glogger, logging_trivial::error) << "[" << basename(file)
    << ": " << line << "]: " << message;
}

void log_fatal(const char* message, const char* file, int line) {
    BOOST_LOG_SEV(glogger, logging_trivial::fatal) << "[" << basename(file)
    << ": " << line << "]: " << message;
}

}  // namespace tools_log
