#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class User {
    std::string nickname_;
    int score_;
    int linesCompleted_;
public:
    User();
    void increaseScore(int linesCleared);
    void increaseLinesCount(int count);
};

#endif // PLAYER_H
