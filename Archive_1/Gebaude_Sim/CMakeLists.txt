cmake_minimum_required(VERSION 3.5)

project(Gebaude_Sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Gebaude_Sim main.cpp gebaeude.h gebaeude.cpp wohnung.h wohnung.cpp zimmer.h zimmer.cpp)

install(TARGETS Gebaude_Sim
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
