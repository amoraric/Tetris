#ifndef GAME_H
#define GAME_H

#include <memory>

#include "GameState.h"

class Board;
class Brick;
class Direction;
class Difficulty;
class Player;
class Shapes;

class Game {
    std::unique_ptr<Board> board_;
    std::unique_ptr<Shapes> bag_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Brick> currentBrick_;
    std::unique_ptr<Difficulty> difficulty_;
    GameState gameState_;
    int currentTime_;
public:
    Game();
    void calculateScore();
    void update(Direction direction);
    void update(bool clockwise);
    void updateState(GameState state);
    bool isGameOver() const;
};

#endif // GAME_H
