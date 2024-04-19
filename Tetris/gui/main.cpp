#include <iostream>
#include <QApplication>
#include "TetrisView.h"


int main(int argc, char* argv[]){
    QApplication application(argc,argv);
    TetrisView myWindow(10,10);
    myWindow.show();
    myWindow.setCellOccupied(0, 0);
    myWindow.setCellOccupied(1, 1);
    myWindow.setCellOccupied(2, 2);
    return application.exec();
}
