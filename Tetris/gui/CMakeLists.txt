project(gui)

set(SOURCES
    main.cpp
)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(aba_gui ${SOURCES}
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
    DrawBoard.h
    DrawBoard.cpp
    SettingsDialog.h
    SettingsDialog.cpp
    SettingsDialog.ui
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

target_link_libraries(aba_gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets metier)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

