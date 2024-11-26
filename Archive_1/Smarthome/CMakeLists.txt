cmake_minimum_required(VERSION 3.5)

project(Smarthome LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Smarthome main.cpp Device_H.h Light_H.h dimmablelight_H.h Device_F.cpp Light_F.cpp dimmablelight_F.cpp)

install(TARGETS Smarthome
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
