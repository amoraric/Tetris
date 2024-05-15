#include "GuiController.h"


std::shared_ptr<MainWindow> GuiController::mainwindow() const
{
    return mainwindow_;
}

GuiController::GuiController(Facade *facade,std::shared_ptr<MainWindow> mainwindow) : facade_{facade}, mainwindow_{mainwindow}
{}
