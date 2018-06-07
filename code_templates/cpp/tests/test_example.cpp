/** Copyright [year] [organization]
 *
 * @file test_example.cpp
 *
 * @brief Implementation of unit test fixture for example utility.
 * A more elaborate description of unit test fixture. (optional)
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

#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

#include "../src/utils/example.hpp"
#include "config.hpp"

namespace test_example {

class TestExample : public ::testing::Test {
 protected:
    TestExample(void) {
    }

    virtual ~TestExample(void) {
    }

    // helper function  to create good config file
    void create_config(std::string level) {
        std::ofstream conf_file(LOCAL_CONFIG_FILE, std::ofstream::out);
        if (!conf_file) {
            throw std::runtime_error("Unable to create local config file");
        }
        conf_file << "[logger]\n" << "level=" << level << "\n\n";
        conf_file << "[options]\n" << "name=example_one\n";
        conf_file.close();
    }

    // helper function to delete config file
    void delete_config(void) {
        std::remove(LOCAL_CONFIG_FILE);
    }

    // helper function to delete log file
    void delete_log(void) {
        std::remove(LOCAL_LOG_FILE);
    }
};

TEST_F(TestExample, ExecutesExampleFunction) {
    create_config("INFO");
    example::Example example;
    EXPECT_EQ(example.example_function(0, 0), 0);
    delete_config();
    delete_log();
}

}  // namespace test_example

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
