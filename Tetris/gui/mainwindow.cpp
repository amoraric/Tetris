#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include <QGraphicsView>
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _scene(new QGraphicsScene(this)),
    drawBoard(std::make_unique<DrawBoard>(_scene))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setFocusPolicy(Qt::StrongFocus);
    foreach(QWidget* w, this->findChildren<QWidget*>()) {
        if (w != ui->graphicsView) {
            w->setFocusPolicy(Qt::NoFocus);
        }
    }

    // because the graphicsView hasn't initialized yet so the width and height is wrong if we don't wait
    QTimer::singleShot(0, this, [this]() {
        drawBoard->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
    });

    connect(ui->settingsButton, &QPushButton::clicked, this, [this]() {
        SettingsDialog settingsDialog(this);
        if (settingsDialog.exec() == QDialog::Accepted) {
            int columns = settingsDialog.getWidth();
            int rows = settingsDialog.getHeight();
            drawBoard->setSize(columns, rows);
            drawBoard->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
        }
    });

    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::onPlayButtonClicked);
}

void MainWindow::onPlayButtonClicked() {
    ui->graphicsView->setFocus();
    std::pair<int, int> size = this->drawBoard->getBoardSize();
    facade_ = std::make_unique<Facade>("Player 1", 1, size.first, size.second);
    facade_->addObserver(shared_from_this());

    startGame();
}

void MainWindow::startGame() {
    update();
    ui->graphicsView->setFocus();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::gameLoop);
    timer->start(100);
}

void MainWindow::gameLoop() {
    if (!facade_->isGameOver()) {
        update();
        if (facade_->isGameOver()) {
            qDebug() << "Brick has settled";
        }
    } else {
        QTimer::singleShot(0, this, [this]() { facade_->end(); });
        qDebug() << "Game over";
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Left:
            facade_->translation(StaticDirections::LEFT);
            break;
        case Qt::Key_Right:
            facade_->translation(StaticDirections::RIGHT);
            break;
        case Qt::Key_Down:
            facade_->translation(StaticDirections::DOWN);
            break;
        case Qt::Key_Space:
            facade_->drop();
            break;
        case Qt::Key_Up:
            facade_->rotation(true);
            break;
        default:
            QWidget::keyPressEvent(event);
    }
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    if (drawBoard && ui->graphicsView->scene()) {
        drawBoard->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
    }
}

void MainWindow::update() {
    if (facade_ && !facade_->isGameOver()) {
        auto boardState = facade_->game()->board()->getBoard();
        auto [currentPosition, currentBrick] = facade_->getBrickDetails();

        drawBoard->updateBoard(boardState, currentPosition, currentBrick);
    }
}
