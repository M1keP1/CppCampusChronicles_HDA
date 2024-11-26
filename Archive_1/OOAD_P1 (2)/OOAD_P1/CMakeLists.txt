
cmake_minimum_required(VERSION 3.10)

project(OOAD_P1 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the main executable
add_executable(OOAD_P1
    main.cpp
    token.h token.cpp
    calculator.h calculator.cpp
)

# Include directories for headers (optional, depending on project structure)
target_include_directories(OOAD_P1 PRIVATE ${CMAKE_SOURCE_DIR})

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Build GoogleTest
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add the test executable
add_executable(calculator_test calculator_test.cpp calculator.h calculator.cpp token.h token.cpp)

# Link GoogleTest libraries to the test executable
target_link_libraries(calculator_test GTest::gtest_main)

# Discover tests
include(GoogleTest)
gtest_discover_tests(calculator_test)

# Install the main executable (optional)
include(GNUInstallDirs)
install(TARGETS OOAD_P1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
