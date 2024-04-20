#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qgraphicsscene.h>
#include "DrawBoard.h"
#include <memory>
#include "Facade.h"
#include "QAction"

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
    void resizeEvent(QResizeEvent *event) override;
    void onPlayButtonClicked();
    void startGame();
    void gameLoop();
    void keyPressEvent(QKeyEvent *event) override;
    QAction getPendingAction();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *_scene;
    std::unique_ptr<DrawBoard> drawBoard;
    std::unique_ptr<Facade> facade_;
};

#endif // MAINWINDOW_H
