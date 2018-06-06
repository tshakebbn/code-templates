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

#include "../src/utils/example.hpp"

namespace test_example {

// redefine for use in unit test
#undef LOG_FILE
#undef CONFIG_FILE
#define LOG_FILE "./unit_test.log"
#define CONFIG_FILE "./unit_test.conf"

class TestExample : public ::testing::Test {
 protected:
    TestExample(void) {
    }

    virtual ~TestExample(void) {
    }

 private:
    example::Example example;
};

TEST_F(TestExample, ExecutesExampleFunction) {
    EXPECT_EQ(example.function(0, 0), 0);
}

}  // namespace test_example

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
