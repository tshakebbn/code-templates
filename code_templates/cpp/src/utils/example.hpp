/** Copyright [year] [organization]
 *
 * @file example.hpp
 *
 * @brief An example utility.
 * A more elaborate description of example utility. (optional)
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

#ifndef CODE_TEMPLATES_CPP_SRC_UTILS_EXAMPLE_HPP_
#define CODE_TEMPLATES_CPP_SRC_UTILS_EXAMPLE_HPP_

/**
 * Namespace documentation.
 */
namespace example {

/**
 * An example enum.
 * A more elaborate description of example enum.
 */
enum ExampleEnum {
    first_value,  /**< Brief description of variable. */
    second_value  /**< Brief description of variable. */
};

/**
 * An example structure.
 * A more elaborate description of example structure.
 */
struct ExampleStruct {
    int first_value;  /**< Brief description of variable. */
    int second_value;  /**< Brief description of variable. */
};

/**
 * An example class.
 * A more elaborate description of example class.
 */
class Example {
 public:
    /**
     * A brief description of the constructor.
     * @throws std::runtime_error       error interfacing with config file
     * @throws std::invalid_argument    invalid argument in config file
     * @throws boost::exception         missing argument in config file
     */
    Example(void);

    /**
     * A brief description of the destructor.
     */
    virtual ~Example(void);

    /**
     * An example function description.
     * @param   value   an input parameter description
     * @param   size    an input parameter description
     * @return          an output value description
     */
    int example_function(int value, int size);

 private:
    int private_variable;
};

}  // namespace example

#endif  // CODE_TEMPLATES_CPP_SRC_UTILS_EXAMPLE_HPP_
