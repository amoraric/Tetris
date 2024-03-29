#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include "Board.h"

class View {
public:
    void welcome();
    void display(Board board, Position p, BrickModel b);
    std::pair<std::string,int> configure();
    void gameOver();
};

#endif // VIEW_H
