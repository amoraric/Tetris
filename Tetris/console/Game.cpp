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
    currentBrick_ = std::make_unique<Brick>(model,*board_);
}

void Game::calculateScore()
{
    if(currentBrick_->getBrickState() == BrickState::ACCOMPLISHED){
        player_->increaseScore(board_->getCompletedLines().size(),difficulty_->getLevel(),currentBrick_->getUpperLeft()->get_y());
        player_->increaseLinesCount(board_->getCompletedLines().size());
        if(player_->getLinesCompleted() >= difficulty_->getMaxLines()){
           if(!difficulty_->nextDifficulty()){
               gameState_ = GameState::FINISHED;
           }
        }
    }
}

void Game::update(Direction direction)
{

}

void Game::update(bool clockwise)
{

}
