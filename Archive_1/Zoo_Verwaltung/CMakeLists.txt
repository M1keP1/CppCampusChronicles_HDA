cmake_minimum_required(VERSION 3.5)

project(Zooverwaltung LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Zooverwaltung main.cpp Herde_H.h Herde_F.cpp Gehege_F.cpp Gehege_H.h Zooverwaltung_H.h Zooverwaltung_F.cpp Raubtiere_F.cpp Raubtiere_H.h)

install(TARGETS Zooverwaltung
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
