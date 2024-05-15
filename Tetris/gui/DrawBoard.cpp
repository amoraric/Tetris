#include "DrawBoard.h"
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
            rect->setBrush(QColor(153, 204, 255));
            rect->setPen(QPen(Qt::darkBlue));
        }
    }
}

void DrawBoard::updateBoard(const std::vector<std::vector<bool>>& staticBoard, const Position& currentPosition, const BrickModel& currentBrick) {
    scene->clear();

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            QGraphicsRectItem *rect = scene->addRect(j * blockSize, i * blockSize, blockSize, blockSize);
            rect->setBrush(staticBoard[i][j] ? Qt::green : Qt::white); // Settled blocks are green, empty cells are white
            rect->setPen(QPen(Qt::gray));
        }
    }

    for (const Position& pos : currentBrick.model) {
        int x = currentPosition.get_x() + pos.get_x();
        int y = currentPosition.get_y() + pos.get_y();
        if (x >= 0 && x < numRows && y >= 0 && y < numColumns) {
            QGraphicsRectItem *rect = scene->addRect(y * blockSize, x * blockSize, blockSize, blockSize);
            rect->setBrush(Qt::red);
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
            rect->setBrush(QColor(153, 204, 255));
            rect->setPen(QPen(Qt::darkBlue));
        }
    }
}
