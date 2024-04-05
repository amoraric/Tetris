#include "Player.h"
Player::Player(std::string nickname) : nickname_{nickname}, score_{0}
{}

void Player::increaseScore(int linesCleared, int level, int distance)
{
    if(linesCleared <= 1){
        score_+=(40*linesCleared+distance)*level;
    }
    else if(linesCleared == 2){
        score_+=(100*linesCleared+distance)*level;
    }
    else if(linesCleared == 3){
        score_+=(300*linesCleared+distance)*level;
    }
    else {
        score_+=(1200*linesCleared+distance)*level;
    }
}

void Player::increaseLinesCount(int count)
{
    linesCompleted_+=count;
}

int Player::getScore()
{
    return score_;
}

int Player::getLinesCompleted()
{
    return linesCompleted_;
}

