cmake_minimum_required(VERSION 3.5)

project(Mensa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Mensa main.cpp mensa_H.h Mensa_F.cpp)

install(TARGETS Mensa
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
