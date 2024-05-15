#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H
#include "mainwindow.h"
class ViewController{
    std::unique_ptr<MainWindow> window;
    std::unique_ptr<Facade> facade;

public:
    ViewController( std::unique_ptr<Facade> facade);
    Facade*getFacade() const;
    MainWindow*getWindow() const;
    void connectButtons();
    void openSettingsDialog();
};

#endif // VIEWCONTROLLER_H
