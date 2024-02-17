#ifndef DIRECTION_H
#define DIRECTION_H

class Direction {
    int dx_;
    int dy_;

public:
    Direction(int x, int y);
    static const Direction LEFT;
    static const Direction DOWN;
    static const Direction RIGHT;
    int getDx() const;
    int getDy() const;
};

#endif // DIRECTION_H
