cmake_minimum_required(VERSION 3.5)

project(OOAD_P1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OOAD_P1 main.cpp
    token.h token.cpp
    calculator.h calculator.cpp)

include(GNUInstallDirs)
install(TARGETS OOAD_P1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
