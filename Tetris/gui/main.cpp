#include <QApplication>
#include "mainwindow.h"


int main(int argc, char* argv[]){
    QApplication application(argc,argv);

    auto myWindow = std::make_shared<MainWindow>();
    myWindow->show();
    return application.exec();
}
