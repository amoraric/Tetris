#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsItemGroup>

class Brick : public QGraphicsItemGroup
{
public:
    Brick();

private:
    void createTShape();
};

#endif // BRICK_H
