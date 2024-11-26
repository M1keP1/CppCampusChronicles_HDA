cmake_minimum_required(VERSION 3.5)

project(Zeitung LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Zeitung main.cpp
    zeitung.h zeitung.cpp
    abonnent.h abonnent.cpp
    zeitungsverlag.h zeitungsverlag.cpp)

include(GNUInstallDirs)
install(TARGETS Zeitung
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
