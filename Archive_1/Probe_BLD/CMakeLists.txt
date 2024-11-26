cmake_minimum_required(VERSION 3.5)

project(Probe_BLD LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Probe_BLD main.cpp
    versicherer.h versicherer.cpp
    vschein.h vschein.cpp
    kfzschein.h kfzschein.cpp
    lvschein.h lvschein.cpp)

include(GNUInstallDirs)
install(TARGETS Probe_BLD
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
