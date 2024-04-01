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
        Facade.cpp
        Controller.cpp
)

add_executable(main ${SOURCES}
)

target_link_libraries(main metier)
