cmake_minimum_required(VERSION 3.5)

project(Tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(metier)
add_subdirectory(console)
add_subdirectory(tests)
add_subdirectory(gui)

set(CMAKE_CXX_FLAGS "-Wpedantic -Werror")

#include(GNUInstallDirs)
#install(TARGETS Tetris
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)
