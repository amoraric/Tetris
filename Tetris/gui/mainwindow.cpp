#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgridlayout.h"
#include "TetrisView.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _scene(this)
{
    ui->setupUi(this);
    TetrisView* myTetris = new TetrisView(10, 10, this);
    myTetris->setCellOccupied(0, 0);
    ui->game_layout->addWidget(myTetris);
}

MainWindow::~MainWindow()
{
    delete ui;
}
