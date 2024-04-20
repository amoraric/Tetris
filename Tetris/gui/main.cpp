#include <QApplication>
#include "mainwindow.h"


int main(int argc, char* argv[]){
    QApplication application(argc,argv);

    MainWindow myWindow;
    myWindow.setFixedSize(1000, 700);
    myWindow.show();
    return application.exec();
}
