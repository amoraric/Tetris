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
    HelpDialog.ui
    HelpDialog.h
    HelpDialog.cpp
    DrawBoard.h
    DrawBoard.cpp
    SettingsDialog.h
    SettingsDialog.cpp
    SettingsDialog.ui
    GuiController.h
    GuiController.cpp
    gameoverdialog.cpp
    gameoverdialog.h
    gameoverdialog.ui
    ../console/Direction.cpp
    ../console/Position.cpp
    ../console/Brick.cpp
    ../console/BrickBag.cpp
    ../console/BrickModel.cpp
    ../console/Board.cpp
    ../console/Difficulty.cpp
    ../console/Player.cpp
    ../console/Game.cpp
    ../console/Facade.cpp
)

set_target_properties(aba_gui PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(aba_gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets metier)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

