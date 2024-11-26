cmake_minimum_required(VERSION 3.5)

project(Battleship LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Battleship main.cpp Schiff_H.h Ship_H.h spielfeld_F.cpp Spielfeld_H.h )

install(TARGETS Battleship
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
