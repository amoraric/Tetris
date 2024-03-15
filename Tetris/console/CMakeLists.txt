project(console)

set(SOURCES
        main.cpp
        Direction.cpp
        Position.cpp
        Brick.cpp
        BrickBag.cpp
        BrickModel.cpp
        Board.cpp
)

add_executable(main ${SOURCES}
    Difficulty.cpp
)

target_link_libraries(main metier)
