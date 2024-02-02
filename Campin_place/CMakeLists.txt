cmake_minimum_required(VERSION 3.5)

project(Campin_place LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Campin_place main.cpp Booking_header.h Booking_func.cpp Plot_header.h Plot_func.cpp Camping_header.h Camping_func.cpp)

install(TARGETS Campin_place
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
