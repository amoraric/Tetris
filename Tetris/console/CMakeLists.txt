project(console)

set(SOURCES
        main.cpp
        Direction.cpp
        Position.cpp
        Brick.cpp
        BrickBag.cpp
        BrickModel.cpp
        Board.cpp
        Difficulty.cpp
        Player.cpp
        Game.cpp
        View.cpp

)

add_executable(main ${SOURCES}
    Facade.cpp
)

target_link_libraries(main metier)
