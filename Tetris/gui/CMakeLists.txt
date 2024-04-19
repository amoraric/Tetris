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
    TetrisView.h
)
target_link_libraries(aba_gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

