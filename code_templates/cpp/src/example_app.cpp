/** Copyright [year] [organization]
 *
 * @file example_app.cpp
 *
 * @brief An example app.
 * A more elaborate description of example app. (optional)
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

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

#include <boost/program_options.hpp>
#include <boost/exception/diagnostic_information.hpp>

#include "utils/example.hpp"
#include "config.hpp"

namespace program_options = boost::program_options;

int main(int argc, char* argv[]) {
    std::string config_value;
    std::string command_value_one;
    int command_value_two;

    program_options::options_description generic("Generic options");
    program_options::options_description command("Command line options");
    program_options::options_description all("Allowed options");
    program_options::options_description config("Config file options");
    program_options::variables_map conf_variables_map;
    program_options::variables_map cmd_variables_map;

    try {
        // setup options
        generic.add_options()
            ("version,v", "print current version")
            ("help,h", "produce help message");
        command.add_options()
            ("value_one",
                program_options::value
                    <std::string>(&command_value_one)->required(),
                "example string command line option")
            ("value_two",
                program_options::value<int>(&command_value_two)->required(),
                "example int command line option");
        all.add(generic).add(command);
        config.add_options()
            ("options.name",
                program_options::value<std::string>(&config_value)->required(),
                "example string config file option");

        // load command line options
        program_options::store(
            program_options::parse_command_line(argc, argv, all),
            cmd_variables_map);

        if (cmd_variables_map.count("version")) {
            std::cout << "C++ Example App version " << VERSION << std::endl;
            return EXIT_SUCCESS;
        }

        if (cmd_variables_map.count("help")) {
            std::cout << all << std::endl;
            return EXIT_SUCCESS;
        }
        program_options::notify(cmd_variables_map);

        // load conf file
        std::ifstream conf_file(CONFIG_FILE, std::ifstream::in);
        if (!conf_file) {
            throw std::runtime_error("Missing configuration file");
        }
        program_options::store(
            program_options::parse_config_file(conf_file, config, true),
            conf_variables_map);
        conf_file.close();
        program_options::notify(conf_variables_map);

        example::Example example;
        if (example.example_function(0, 0)) {
            throw std::runtime_error("Example function returned bad value");
        }
    } catch (boost::exception const &ex) {
        std::cerr << boost::diagnostic_information(ex) << std::endl;
        std::cout << all << std::endl;
        return EXIT_FAILURE;
    } catch(std::runtime_error &ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    } catch(std::invalid_argument &ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Command value one: " << command_value_one << std::endl;
    std::cout << "Command value two: " << command_value_two << std::endl;
    std::cout << "Config value: " << config_value << std::endl;

    return EXIT_SUCCESS;
}
