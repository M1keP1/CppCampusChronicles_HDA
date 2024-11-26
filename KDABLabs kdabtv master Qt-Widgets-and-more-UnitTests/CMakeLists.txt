cmake_minimum_required(VERSION 3.9)
project(CalculatorProject)

# Set C++ standard and include the current directory
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find required Qt packages (Core and Test)
find_package(QT NAMES Qt5 Qt6 CONFIG REQUIRED COMPONENTS Core Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test)

# Enable automatic moc and rcc handling for Qt
set(CMAKE_AUTOMOC TRUE)
set(CMAKE_AUTORCC TRUE)

target_sources(QWAM
  PRIVATE
    calculator.cpp
)

# Add your source files for the Calculator program
add_library(CalculatorLib SHARED Calculator.cpp)

# Link QtCore to CalculatorLib
target_link_libraries(CalculatorLib Qt${QT_VERSION_MAJOR}::Core)

# Create the executable QWAM from main.cpp
add_executable(CalculatorApp main.cpp)

# Link CalculatorLib to the CalculatorApp executable
target_link_libraries(CalculatorApp CalculatorLib)

# Add the Tests subdirectory (where you will put your unit tests)
add_subdirectory(Tests)
