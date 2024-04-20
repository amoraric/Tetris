#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"
#include "settingsdialog.h"
#include <QGraphicsView>
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _scene(new QGraphicsScene(this)),
    board(std::make_unique<Board>(_scene))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(_scene);

    // because the graphicsView hasn't initialized yet so the width and height is wrong if we don't wait
    QTimer::singleShot(0, this, [this]() {
        board->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
    });

    connect(ui->settingsButton, &QPushButton::clicked, this, [this]() {
        SettingsDialog settingsDialog(this);
        if (settingsDialog.exec() == QDialog::Accepted) {
            int columns = settingsDialog.getWidth();
            int rows = settingsDialog.getHeight();
            board->setSize(columns, rows);
            board->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    if (board && ui->graphicsView->scene()) {
        board->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
    }
}
