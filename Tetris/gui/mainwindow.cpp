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
    drawBoard(std::make_unique<DrawBoard>(_scene)),
    facade_(nullptr),
    level_(1),
    nickname_("Anonymous")
{
    ui->setupUi(this);
    ui->graphicsView->setScene(_scene);
    this->setFocusPolicy(Qt::StrongFocus);

    // because the graphicsView hasn't initialized yet so the width and height is wrong if we don't wait 
    QTimer::singleShot(0, this, [this]() {
        drawBoard->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
    });

    connectButtons();
}

void MainWindow::connectButtons() {
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::openSettingsDialog);
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::onPlayButtonClicked);
    connect(ui->exitButton, &QPushButton::clicked, QApplication::quit);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (!facade_ || facade_->isGameOver()) {
        QMainWindow::keyPressEvent(event);
        return;
    }

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

void MainWindow::openSettingsDialog() {
    SettingsDialog settingsDialog(this);
    if (settingsDialog.exec() == QDialog::Accepted) {
        level_ = settingsDialog.getLevel();
        nickname_ = settingsDialog.getNickname();
        int columns = settingsDialog.getWidth();
        int rows = settingsDialog.getHeight();
        drawBoard->setSize(columns, rows);
        drawBoard->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
    }
}

void MainWindow::onPlayButtonClicked() {
    if (facade_ && !facade_->isGameOver()) {
        onEndGameButtonClicked();
        return;
    }

    ui->settingsButton->setDisabled(true);
    ui->playButton->setText("End Game");
    std::pair<int, int> size = drawBoard->getBoardSize();
    facade_ = std::make_unique<Facade>(nickname_, level_, size.first, size.second);
    facade_->addObserver(shared_from_this());
    startGame();
}

void MainWindow::onEndGameButtonClicked() {
    if (!facade_) return;

    facade_->end();
    ui->playButton->setText("Play");
    ui->settingsButton->setEnabled(true);
    drawBoard->reset();
}

void MainWindow::startGame() {
    update();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::gameLoop);
    // cause we have 25lvls so the ultimate time is 100ms (>0)
    timer->start(1100 - (facade_->getLevel() * 40));
}

void MainWindow::gameLoop() {
    if (facade_ && !facade_->isGameOver()) {
        facade_->translation(StaticDirections::DOWN);
        update();
    } else {
        onEndGameButtonClicked();
    }
}

void MainWindow::updateGameStats() {
    QFont labelFont = ui->score_label->font();
    labelFont.setPointSize(16);
    if (facade_) {
        QString scoreText = QString("Score: %1").arg(facade_->getScore());
        ui->score_label->setText(scoreText);
        ui->score_label->setFont(labelFont);

        QString levelText = QString("Level: %1").arg(facade_->getLevel());
        ui->level_label->setText(levelText);
        ui->level_label->setFont(labelFont);

        QString linesText = QString("Lines Completed: %1").arg(facade_->getLinesCompleted());
        ui->lines_label->setText(linesText);
        ui->lines_label->setFont(labelFont);

        QString timeText = QString("Time: %1").arg(getFormattedTime());
        ui->time_label->setText(timeText);
        ui->time_label->setFont(labelFont);
    }
}

QString MainWindow::getFormattedTime() {
    return "00:00:00";
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
        updateGameStats();
        auto boardState = facade_->game()->board()->getBoard();
        auto [currentPosition, currentBrick] = facade_->getBrickDetails();
        drawBoard->updateBoard(boardState, currentPosition, currentBrick);
    }
}
