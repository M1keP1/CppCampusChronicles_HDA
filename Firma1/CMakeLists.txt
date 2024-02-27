cmake_minimum_required(VERSION 3.5)

project(Firma1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Firma1 main.cpp human_H.h City_H.h Company_H.h City_F.cpp Human_F.cpp Company_f.cpp)

install(TARGETS Firma1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
