project(tests)

set(TEST_SOURCES
    catch_amalgamated.cpp
    catch_amalgamated.hpp
    tests.cpp
    ../console/Direction.cpp
    ../console/Position.cpp
    ../console/Brick.cpp
    ../console/BrickBag.cpp
    ../console/BrickModel.cpp
    ../console/Board.cpp
    ../console/Difficulty.cpp
    ../console/Player.cpp
    ../console/Game.cpp
    ../console/View.cpp
    ../console/Facade.cpp
    ../console/Controller.cpp
)

add_executable(aba_tests ${TEST_SOURCES})
set_target_properties(aba_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(aba_tests metier)
