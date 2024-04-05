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
set_target_properties(aba_cons PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(aba_cons metier)
