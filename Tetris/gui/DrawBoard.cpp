#include "DrawBoard.h"
#include "BrickBag.h"
#include <QGraphicsRectItem>
#include <QPen>

DrawBoard::DrawBoard(QGraphicsScene *scene) : scene(scene), blockSize(30), numColumns(10), numRows(20)
{
}

void DrawBoard::setSize(int columns, int rows) {
    numColumns = columns;
    numRows = rows;
}

std::pair<int, int> DrawBoard::getBoardSize()
{
    return {this->numRows, this->numColumns};
}

int DrawBoard::calculateBlockSize(int width, int height) {
    int blockWidth = width / numColumns;
    int blockHeight = height / numRows;
    return std::min(blockWidth, blockHeight); // Use the smallest to ensure blocks fit
}

void DrawBoard::drawGrid(int viewWidth, int viewHeight) {
    blockSize = calculateBlockSize(viewWidth, viewHeight);
    scene->clear();

    int exactWidth = numColumns * blockSize;
    int exactHeight = numRows * blockSize;
    scene->setSceneRect(0, 0, exactWidth, exactHeight);

    for (int i = 0; i < exactHeight; i += blockSize) {
        for (int j = 0; j < exactWidth; j += blockSize) {
            QGraphicsRectItem *rect = scene->addRect(j, i, blockSize, blockSize);
            rect->setBrush(QColor(0, 102, 255));
            rect->setPen(QColor(0, 0, 153));
        }
    }
}

void DrawBoard::updateBoard(const std::vector<std::vector<bool>>& staticBoard, const Position& currentPosition, const BrickModel& currentBrick) {
    scene->clear();

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            QGraphicsRectItem *rect = scene->addRect(j * blockSize, i * blockSize, blockSize, blockSize);
            rect->setBrush(QColor(0, 102, 255));
            rect->setPen(QColor(0, 0, 153));
            if (staticBoard[i][j]) {
                rect->setBrush(QColor(255, 0, 255));
                rect->setPen(QPen(Qt::black));
            }
        }
    }
    if(currentBrick.model == StaticBrickModels::O.model){
        color.setRgb(255,255,0);
    }
    else if(currentBrick.model == StaticBrickModels::I.model){
        color.setRgb(204,255,255);
    }
    else if(currentBrick.model == StaticBrickModels::L.model){
        color.setRgb(0,0,255);
    }
    else if(currentBrick.model == StaticBrickModels::J.model){
         color.setRgb(255,178,102);
    }
    else if(currentBrick.model == StaticBrickModels::S.model){
        color.setRgb(0,204,0);
    }
    else if(currentBrick.model == StaticBrickModels::T.model){
        color.setRgb(204,0,204);
    }
    else if(currentBrick.model == StaticBrickModels::Z.model){
        color.setRgb(255,0,0);
    }

    for (const Position& pos : currentBrick.model) {
        int x = currentPosition.get_x() + pos.get_x();
        int y = currentPosition.get_y() + pos.get_y();
        if (x >= 0 && x < numRows && y >= 0 && y < numColumns) {
            QGraphicsRectItem *rect = scene->addRect(y * blockSize, x * blockSize, blockSize, blockSize);
            rect->setBrush(color);
            rect->setPen(QPen(Qt::black));
        }
    }
}

void DrawBoard::reset() {
    scene->clear();

    blockSize = calculateBlockSize(scene->width(), scene->height());
    int exactWidth = numColumns * blockSize;
    int exactHeight = numRows * blockSize;
    scene->setSceneRect(0, 0, exactWidth, exactHeight);

    for (int i = 0; i < exactHeight; i += blockSize) {
        for (int j = 0; j < exactWidth; j += blockSize) {
            QGraphicsRectItem *rect = scene->addRect(j, i, blockSize, blockSize);
            rect->setBrush(QColor(0, 102, 255));
            rect->setPen(QColor(0, 0, 153));
        }
    }
}
