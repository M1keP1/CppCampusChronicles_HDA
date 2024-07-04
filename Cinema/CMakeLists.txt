cmake_minimum_required(VERSION 3.5)

project(Cinema LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cinema main.cpp book.h book.cpp cinema.h cinema.cpp seat.cpp seat.h doppelseat.h doppelseat.cpp)

install(TARGETS Cinema
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
