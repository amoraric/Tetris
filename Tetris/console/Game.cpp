#include "Game.h"
#include <cstdlib>
#include <ctime>
Board*Game::board() const
{
    return board_.get();
}

Game::Game(std::string nickname, int level) : gameState_{GameState::READY}, currentTime_{0}
{
    board_ =std::make_unique<Board>(20,10);
    bag_= std::make_unique<BrickBag>();
    difficulty_ = std::make_unique<Difficulty>(level);
    player_ = std::make_unique<Player>(nickname);
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
   *currentBrick_+direction;
}

void Game::update(bool clockwise)
{
    currentBrick_->rotation(clockwise);
}

void Game::updateState(GameState state)
{
    this->gameState_ = state;
}

GameState Game::getGameState() const
{
    return this->gameState_;
}

void Game::drop()
{
    while(this->currentBrick_->canMove(*board_,StaticDirections::DOWN)){
        update(StaticDirections::DOWN);
    }
}

std::pair<Position, BrickModel> Game::getBrickDetails()
{
    return std::make_pair(*this->currentBrick_->getUpperLeft(),*this->currentBrick_->getBrickModel());
}


