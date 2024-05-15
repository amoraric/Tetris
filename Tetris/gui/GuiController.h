#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H
#include "mainwindow.h"
#include "Facade.h"
class GuiController{
    std::unique_ptr<Facade> facade_;
    std::shared_ptr<MainWindow> mainwindow_;
 public:
    GuiController(Facade* facade, std::shared_ptr<MainWindow> mainwindow);

    std::shared_ptr<MainWindow> mainwindow() const;
};

#endif // GUICONTROLLER_H
