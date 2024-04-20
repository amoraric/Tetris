#include "brick.h"
#include <QGraphicsRectItem>
#include <QBrush>

Brick::Brick()
{
    createTShape();
}

void Brick::createTShape()
{
    int blockSize = 30;

    // Create the T shape using 4 blocks
    QGraphicsRectItem *block1 = new QGraphicsRectItem(0, 0, blockSize, blockSize);
    QGraphicsRectItem *block2 = new QGraphicsRectItem(blockSize, 0, blockSize, blockSize);
    QGraphicsRectItem *block3 = new QGraphicsRectItem(2 * blockSize, 0, blockSize, blockSize);
    QGraphicsRectItem *block4 = new QGraphicsRectItem(blockSize, blockSize, blockSize, blockSize);

    // Set color and style
    QBrush brush(Qt::blue);
    block1->setBrush(brush);
    block2->setBrush(brush);
    block3->setBrush(brush);
    block4->setBrush(brush);

    // Add blocks to the group
    addToGroup(block1);
    addToGroup(block2);
    addToGroup(block3);
    addToGroup(block4);
}
