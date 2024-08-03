cmake_minimum_required(VERSION 3.5)

project(Praktikum5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Praktikum5 main.cpp
    zimmer.h zimmer.cpp
    wohnung.h wohnung.cpp
    gebaeude.h gebaeude.cpp)

include(GNUInstallDirs)
install(TARGETS Praktikum5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
