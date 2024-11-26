# Find required Qt Test module
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

# Add the test source file for the Calculator
add_executable(tst_calculator tst_calculator.cpp)

# Link the necessary libraries to the test executable
target_link_libraries(tst_calculator Qt${QT_VERSION_MAJOR}::Test CalculatorLib)

# Enable testing
enable_testing()

# Register the test
add_test(NAME CalculatorTest COMMAND tst_calculator)
