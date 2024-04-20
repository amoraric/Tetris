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
    int calculateBlockSize(int width, int height);
    void setSize(int newWidth, int newHeight);
    std::pair<int, int> getBoardSize();
    void updateBoard(const std::vector<std::vector<bool>>& staticBoard, const Position& currentPosition, const BrickModel& currentBrick);

private:
    QGraphicsScene *scene;
    int numColumns;
    int numRows;
    int blockSize;
};

#endif // DRAWBOARD_H
