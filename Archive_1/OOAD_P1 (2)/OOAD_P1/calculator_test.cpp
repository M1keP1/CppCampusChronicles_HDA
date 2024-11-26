#include <gtest/gtest.h>
#include "Calculator.h"
#include <string>

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calculator;

    void SetUp() override {
        // Define variables to be used in the test cases
        calculator.define("pi", 3.1415);
        calculator.define("r", 4);
    }
};

// Test valid expression
TEST_F(CalculatorTest, ValidExpression) {
    std::string expression = "2*pi*r";
    try {
        double result = calculator.computeValue(expression);
        EXPECT_NEAR(result, 25.132, 0.001); // Expected output: approximately 25.132
    } catch (const std::exception& e) {
        FAIL() << "Exception thrown: " << e.what();
    }
}

// Test invalid expression
TEST_F(CalculatorTest, InvalidExpression) {
    std::string expression = "2*pi+";
    try {
        calculator.computeValue(expression);
        FAIL() << "Expected an exception for invalid expression.";
    } catch (const std::exception& e) {
        SUCCEED();
    }
}

// Test undefined variable
TEST_F(CalculatorTest, UndefinedVariable) {
    std::string expression = "2*pi*x"; // x is not defined
    try {
        calculator.computeValue(expression);
        FAIL() << "Expected an exception for undefined variable.";
    } catch (const std::exception& e) {
        SUCCEED();
    }
}

// Test without defining any variables
TEST(CalculatorStandaloneTest, NoDefinedVariables) {
    Calculator standaloneCalculator;
    std::string expression = "2*pi*r";
    try {
        standaloneCalculator.computeValue(expression);
        FAIL() << "Expected an exception for undefined variables.";
    } catch (const std::exception& e) {
        SUCCEED();
    }
}
