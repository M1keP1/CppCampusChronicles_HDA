cmake_minimum_required(VERSION 3.5)

project(CampingPlatz LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CampingPlatz main.cpp Booking_H.h Booking_F.cpp Plot_H.h Plot_F.cpp Camping_H.h Camping_F.cpp)

install(TARGETS CampingPlatz
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
