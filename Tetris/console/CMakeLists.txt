project(console)

set(SOURCES
        main.cpp
        Direction.cpp
        Position.cpp
        Brick.cpp
)

add_executable(main ${SOURCES}
    BrickBag.cpp
    BrickModel.cpp
)

target_link_libraries(main metier)
