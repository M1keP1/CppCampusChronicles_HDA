cmake_minimum_required(VERSION 3.5)

project(stargate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stargate main.cpp
    raumflug.h raumflug.cpp
    raumgleiter.h raumgleiter.cpp
    raumfahrtunternehmen.h raumfahrtunternehmen.cpp)

include(GNUInstallDirs)
install(TARGETS stargate
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
