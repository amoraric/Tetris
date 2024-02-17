#ifndef POSITION_H
#define POSITION_H

#include <utility>

class Position {
    std::pair<int, int> coordinates_;

public:
    Position(int x, int y);
    int get_x() const;
    int get_y() const;
};

#endif // POSITION_H
