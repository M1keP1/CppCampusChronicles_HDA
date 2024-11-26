cmake_minimum_required(VERSION 3.5)

project(Magazine_SubscriptionSys LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Magazine_SubscriptionSys main.cpp zeitungsverlag.h zeitungsverlag.cpp zeitung.h zeitung.cpp abonnent.h abonnent.cpp)

install(TARGETS Magazine_SubscriptionSys
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
