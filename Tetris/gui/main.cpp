#include <QApplication>
#include "mainwindow.h"


int main(int argc, char* argv[]){
    QApplication application(argc,argv);

    MainWindow myWindow;
    myWindow.show();
    return application.exec();
}
