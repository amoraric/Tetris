project(console)

set(SOURCES
        main.cpp
        Direction.cpp
        Position.cpp
)

add_executable(main ${SOURCES})

target_link_libraries(main metier)
