#include "ViewController.h"
#include "ui_mainwindow.h"
#include "SettingsDialog.h"


Facade*ViewController::getFacade() const
{
    return facade.get();
}

MainWindow*ViewController::getWindow() const
{
    return window.get();
}

ViewController::ViewController(std::unique_ptr<Facade> facade) :  window {new MainWindow}
{
    //connectButtons();
}
void ViewController::openSettingsDialog(){
    SettingsDialog settingsDialog(this->getWindow());
    settingsDialog.exec();
}
