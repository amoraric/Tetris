project(console)

set(SOURCES
        main.cpp
        Direction.cpp
        Position.cpp
)

add_executable(main ${SOURCES}
    BrickBag.cpp
    BrickModel.cpp
    Brick.cpp)

target_link_libraries(main metier)
