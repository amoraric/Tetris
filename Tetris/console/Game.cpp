#include "Game.h"
#include <cstdlib>
#include <ctime>
Game::Game() : gameState_{GameState::READY}, currentTime_{0}
{
    board_ =std::make_unique<Board>(5,10);
    bag_= std::make_unique<BrickBag>();
    difficulty_ = std::make_unique<Difficulty>(1);
    generate();
}

void Game::generate()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomIndex = std::rand() % bag_->getBrickBag().size();
    auto model = bag_->getBrickBag()[randomIndex];
    currentBrick_ = std::make_unique<Brick>(model,board_);

}
