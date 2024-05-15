#ifndef DRAWBOARD_H
#define DRAWBOARD_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "Position.h"
#include "BrickModel.h"

class DrawBoard {
public:
    DrawBoard(QGraphicsScene *scene);
    void drawGrid(int viewWidth, int viewHeight);
    void setSize(int newWidth, int newHeight);
    std::pair<int, int> getBoardSize();
    void updateBoard(const std::vector<std::vector<bool>>& staticBoard, const Position& currentPosition, const BrickModel& currentBrick);
    void reset();

private:
    QGraphicsScene *scene;
    int numColumns;
    int numRows;
    int blockSize;
    int calculateBlockSize(int width, int height);
    QColor color;
};

#endif // DRAWBOARD_H
