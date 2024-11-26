cmake_minimum_required(VERSION 3.5)

project(roulette LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(roulette main.cpp header.h func.cpp)

install(TARGETS roulette
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
