#include <QApplication>
#include "GuiController.h""


int main(int argc, char* argv[]){
    QApplication application(argc,argv);
    Facade* f = new Facade{"a",1,20,10};
    auto myWindow = std::make_shared<MainWindow>();
    auto controller = GuiController(f,myWindow);
    controller.mainwindow()->show();
    return application.exec();
}
