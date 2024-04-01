project(metier)

set(SOURCES
        Position.h
        BrickState.h
        Direction.h
        GameState.h
        Board.h
        Brick.h
        BrickBag.h
        Game.h
        Player.h
        Facade.h
        Difficulty.h
        BrickModel.h
        Observable.h
        Observer.h
        View.h
        Controller.h
        UserActions.h
        main.cpp
)

add_library(metier ${SOURCES})

target_include_directories(metier
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
