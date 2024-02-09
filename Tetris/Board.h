#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Position.h"

class Board {
    std::vector<std::vector<bool>> matrix_;

    bool isInside(Position pos);
};

#endif // BOARD_H
