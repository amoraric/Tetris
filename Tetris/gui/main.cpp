#include <QApplication>
#include "mainwindow.h"
#include "ViewController.h"


int main(int argc, char* argv[]){
    QApplication application(argc,argv);
    //auto myWindow = new MainWindow();
    ViewController c {std::make_unique<Facade>()};
    c.getWindow()->show();
    return application.exec();
}
