cmake_minimum_required(VERSION 3.5)

project(Krankenhaus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Krankenhaus main.cpp Patient_H.h Patient_F.cpp)

install(TARGETS Krankenhaus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
