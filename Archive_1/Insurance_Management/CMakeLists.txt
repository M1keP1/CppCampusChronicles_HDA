cmake_minimum_required(VERSION 3.5)

project(Insurance_Management LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Insurance_Management main.cpp versicherer.h versicherer.cpp kfzschein.h kfzschein.cpp lvschein.h lvschein.cpp)

install(TARGETS Insurance_Management
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
