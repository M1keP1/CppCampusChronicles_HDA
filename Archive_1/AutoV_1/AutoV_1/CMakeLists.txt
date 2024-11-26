cmake_minimum_required(VERSION 3.5)

project(AutoV_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AutoV_1 main.cpp
    fahrt.h fahrt.cpp
    mietwagen.h mietwagen.cpp
    autovermietung.h autovermietung.cpp)

include(GNUInstallDirs)
install(TARGETS AutoV_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
