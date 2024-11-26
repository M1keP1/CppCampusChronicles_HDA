cmake_minimum_required(VERSION 3.5)

project(Callcenter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Callcenter main.cpp
    termin.h termin.cpp
    artztpraxis.h artztpraxis.cpp
    callcenter.h callcenter.cpp)

include(GNUInstallDirs)
install(TARGETS Callcenter
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
