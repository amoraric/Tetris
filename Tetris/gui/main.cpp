#include <iostream>
#include <QApplication>
#include "TetrisView.h"
#include "mainwindow.h"


int main(int argc, char* argv[]){
    QApplication application(argc,argv);


    MainWindow myWindow;
    myWindow.setFixedSize(800, 560);
    myWindow.show();
    return application.exec();
}
