#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include "Board.h"
#include <tuple>

class View {
public:
    static void welcome();
    static void display(Board board, Position p, BrickModel b);
    static std::tuple<std::string,int,bool> configure();
    static void gameOver();
    static std::string askAction();
    static void showStats(std::string nickname, int level, int score, int linesCompleted);
};

#endif // VIEW_H
