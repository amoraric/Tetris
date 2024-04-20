#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Board {
public:
    Board(QGraphicsScene *scene);
    void drawGrid(int viewWidth, int viewHeight);
    int calculateBlockSize(int width, int height);
    void setSize(int newWidth, int newHeight);

private:
    QGraphicsScene *scene;
    int numColumns;
    int numRows;
    int blockSize;
};

#endif // BOARD_H
