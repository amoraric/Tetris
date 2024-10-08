#include "mainwindow.h"
#include "gameoverdialog.h"
#include "helpdialog.h"
#include "ui_mainwindow.h"
#include "SettingsDialog.h"
#include <QGraphicsView>
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _scene(new QGraphicsScene(this)),
    drawBoard(std::make_unique<DrawBoard>(_scene)),
    facade_(nullptr),
    timer_(std::make_unique<QTimer>(this)),
    updateTimer_(std::make_unique<QTimer>(this)),
    level_(1),
    timeMax_(600),
    nickname_("Anonymous")
{
    ui->setupUi(this);
    ui->graphicsView->setScene(_scene);
    this->setFocusPolicy(Qt::StrongFocus);
    foreach(QWidget* w, this->findChildren<QWidget*>()) {
        if (w != ui->graphicsView) {
            w->setFocusPolicy(Qt::NoFocus);
        }
    }

    // because the graphicsView hasn't initialized yet so the width and height is wrong if we don't wait 
    QTimer::singleShot(0, this, [this]() {
        drawBoard->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
    });

    connect(updateTimer_.get(), &QTimer::timeout, this, &MainWindow::updateTimeLabel);

    connectButtons();
    styleButtons();

    QPixmap pixmap("Tetris_logo.png");
    if (pixmap.isNull()) {
        qDebug() << "Failed to load the image.";
    } else {
        if (ui->title_label) {
            QSize targetSize = pixmap.size() * 2;
            QSize maxSize = ui->title_label->maximumSize();
            targetSize.setWidth(qMin(targetSize.width(), maxSize.width()));
            targetSize.setHeight(qMin(targetSize.height(), maxSize.height()));

            // Scale the pixmap while maintaining the aspect ratio
            QPixmap scaledPixmap = pixmap.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            ui->title_label->setPixmap(scaledPixmap);
            ui->title_label->setAlignment(Qt::AlignCenter);
            ui->title_label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
            ui->title_label->setScaledContents(false);
        } else {
            qDebug() << "Label not found.";
        }
    }

    ui->lines_label->setStyleSheet("color: #ccffff;");
    ui->level_label->setStyleSheet("color: #ccffff;");
    ui->score_label->setStyleSheet("color: #ccffff;");
    ui->time_label->setStyleSheet("color: #ccffff;");
}

void MainWindow::connectButtons() {
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::openSettingsDialog);
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::onPlayButtonClicked);
    connect(ui->helpButton, &QPushButton::clicked,this, &MainWindow::openHelpDialog);
    connect(ui->exitButton, &QPushButton::clicked, QApplication::quit);

}

void MainWindow::styleButtons() {
    QString buttonStyle = "QPushButton {"
                          "    background-color: #0066ff;"
                          "    border: 1px solid rgb(0, 0, 0);"
                          "}"
                          "QPushButton:hover {"
                          "    background-color: #0000ff;"
                          "}";

    ui->settingsButton->setStyleSheet(buttonStyle);
    ui->playButton->setStyleSheet(buttonStyle);
    ui->helpButton->setStyleSheet(buttonStyle);
    ui->exitButton->setStyleSheet(buttonStyle);

    ui->rightVLayout->setAlignment(ui->playButton, Qt::AlignHCenter);
    ui->rightVLayout->setAlignment(ui->settingsButton, Qt::AlignHCenter);
    ui->rightVLayout->setAlignment(ui->helpButton, Qt::AlignHCenter);
    ui->rightVLayout->setAlignment(ui->exitButton, Qt::AlignHCenter);
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
    case Qt::Key_Z:
        facade_->rotation(false);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
    update();
}

void MainWindow::openSettingsDialog() {
    if (settingsDialog.exec() == QDialog::Accepted) {
        level_ = settingsDialog.getLevel();
        nickname_ = settingsDialog.getNickname();
        int columns = settingsDialog.getWidth();
        int rows = settingsDialog.getHeight();
        timeMax_ = settingsDialog.getMaxTime();
        drawBoard->setSize(columns, rows);
        drawBoard->drawGrid(ui->graphicsView->width(), ui->graphicsView->height());
        this->randomize_ = settingsDialog.getRandomize();
    }
}

void MainWindow::openHelpDialog(){
    HelpDialog helpdialog(this);
    helpdialog.exec();

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
    if (this->randomize_) {
        facade_->game()->board()->randomize();
    }
    startGame();
}

void MainWindow::onEndGameButtonClicked() {
    if (!facade_) return;
    timer_->stop();
    updateTimer_->stop();
    facade_->end();
    updateGameStats();
    GameOverDialog gameover(this);
    gameover.exec();
    ui->playButton->setText("Play");
    ui->settingsButton->setEnabled(true);
    drawBoard->reset();

}

void MainWindow::updateTimeLabel() {
    if (timeMax_ <= elapsedTimer_.elapsed()/1000000000) {
        facade_->end();
        onEndGameButtonClicked();
    }
    qint64 timeElapsed = elapsedTimer_.elapsed();
    QTime time(0, 0);
    time = time.addMSecs(timeElapsed);
    QString timeText = time.toString("hh:mm:ss.zzz");
    ui->time_label->setText("Time: " + timeText);
    QFont labelFont = ui->score_label->font();
    labelFont.setPointSize(16);
    ui->time_label->setFont(labelFont);
}

void MainWindow::startGame() {
    elapsedTimer_.start();
    updateTimer_->start(10);

    update();
    timer_->stop();
    connect(timer_.get(), &QTimer::timeout, this, &MainWindow::gameLoop, Qt::UniqueConnection);
    timer_->start(1000 * (facade_->getTimeLimit() / 60.0));
}

void MainWindow::gameLoop() {
    if (facade_ && !facade_->isGameOver()) {
        facade_->translation(StaticDirections::DOWN);
    } else {
        timer_->stop();
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
    }
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
