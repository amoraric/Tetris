#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position {
    std::pair<int, int> coordinates_;

public:
    Position(int x, int y);
    int get_x();
    int get_y();
};

#endif // POSITION_H
