cmake_minimum_required(VERSION 3.5)

project(Tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Tetris main.cpp
    Position.h
    BrickState.h
    Direction.h
    GameState.h
    Board.h
    Brick.h
    Shape.h)

set(CMAKE_CXX_FLAGS "-Wpedantic -Werror")

include(GNUInstallDirs)
install(TARGETS Tetris
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
