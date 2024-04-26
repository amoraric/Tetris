#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qgraphicsscene.h>
#include "DrawBoard.h"
#include <memory>
#include "Facade.h"
#include <QElapsedTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Observer, public std::enable_shared_from_this<MainWindow>
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void update() override;
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onPlayButtonClicked();
    void onEndGameButtonClicked();
    void openSettingsDialog();
    void gameLoop();
    void updateGameStats();
    void updateTimeLabel();

private:
    void resizeEvent(QResizeEvent *event) override;
    Ui::MainWindow *ui;
    QGraphicsScene *_scene;
    std::unique_ptr<DrawBoard> drawBoard;
    std::unique_ptr<Facade> facade_;
    std::string nickname_ = "Anonymous";
    int level_ = 1;
    int timeMax_ = 600;
    std::unique_ptr<QTimer> timer_;
    std::unique_ptr<QTimer> updateTimer_;
    QElapsedTimer elapsedTimer_;

    void connectButtons();
    void startGame();
};

#endif // MAINWINDOW_H
