cmake_minimum_required(VERSION 3.5)

project(Lagerverwaltung LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lagerverwaltung main.cpp Artikel_func.cpp Artikel_header.h Lagerplatz_func.cpp Lagerplatz_header.h Lagerverwaltung_func.cpp Lagerverwaltung_header.h GefahrgutLagerplatz_func.cpp gefahrgutLagerplatz_header.h)

install(TARGETS Lagerverwaltung
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
