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

add_executable(aba_cons ${SOURCES}
)

target_include_directories(aba_cons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../metier)
