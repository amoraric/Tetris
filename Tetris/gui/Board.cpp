#include "board.h"
#include <QGraphicsRectItem>
#include <QPen>

Board::Board(QGraphicsScene *scene) : scene(scene), blockSize(30), numColumns(10), numRows(20)
{
}

void Board::setSize(int columns, int rows) {
    numColumns = columns;
    numRows = rows;
}

int Board::calculateBlockSize(int width, int height) {
    int blockWidth = width / numColumns;
    int blockHeight = height / numRows;
    return std::min(blockWidth, blockHeight); // Use the smallest to ensure blocks fit
}

void Board::drawGrid(int viewWidth, int viewHeight) {
    blockSize = calculateBlockSize(viewWidth, viewHeight);
    scene->clear();

    int exactWidth = numColumns * blockSize;
    int exactHeight = numRows * blockSize;
    scene->setSceneRect(0, 0, exactWidth, exactHeight);

    for (int i = 0; i < exactHeight; i += blockSize) {
        for (int j = 0; j < exactWidth; j += blockSize) {
            QGraphicsRectItem *rect = scene->addRect(j, i, blockSize, blockSize);
            rect->setBrush(Qt::lightGray);
            rect->setPen(QPen(Qt::gray));
        }
    }
}
