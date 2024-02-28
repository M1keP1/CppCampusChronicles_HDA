cmake_minimum_required(VERSION 3.5)

project(Furniture LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Furniture main.cpp Furniture_F.cpp Furniture_H.h Table_F.cpp Table_H.h Bed_H.h Bed_F.cpp)

install(TARGETS Furniture
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
