#include "Game.h"
#include <cstdlib>
#include <ctime>

Board*Game::board() const
{
    return board_.get();
}

Brick*Game::currentBrick() const
{
    return currentBrick_.get();
}

std::string Game::getNickname()
{
    return this->player_->getNickname();
}

int Game::getLevel()
{
    return this->difficulty_->getLevel();
}

Game::Game(std::string nickname, int level, int rows, int columns) : gameState_{GameState::READY}
{
    board_ = std::make_unique<Board>(rows,columns);
    bag_= std::make_unique<BrickBag>();
    difficulty_ = std::make_unique<Difficulty>(level);
    player_ = std::make_unique<Player>(nickname);
    generate();
}

void Game::generate()
{
    if (bag_->getBrickBag().size() == 0) {
        bag_= std::make_unique<BrickBag>();
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomIndex = std::rand() % bag_->getBrickBag().size();
    auto model = bag_->getBrickBag()[randomIndex];
    bag_->eraseBrickIndex(randomIndex);

    Position upperLeft {0, (int) board_->getBoard()[0].size()/2};
    std::vector<Position> v {};
    for (int var = 0; var < model.model.size(); ++var) {
        v.push_back({model.model[var].get_x()+upperLeft.get_x(),model.model[var].get_y()+upperLeft.get_y()});
    }
    for (auto vv : v) {
        if (this->board_->isOccupied(vv)) {
            updateState(GameState::FINISHED);
            return;
        }
    }

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

bool Game::update(Direction direction)
{
    auto upperLeft = currentBrick_->getUpperLeft();
    auto model = currentBrick_->getBrickModel()->model;
    std::vector<Position> v {};
    for (int var = 0; var < model.size(); ++var) {
        v.push_back({model[var].get_x()+upperLeft->get_x()+direction.getDx(),model[var].get_y()+upperLeft->get_y() + direction.getDy()});
    }
    for (auto vv : v) {
        if (direction == StaticDirections::DOWN && (vv.get_x() == this->board_->getSize() ||
                                                    this->board_->isOccupied(vv))) {
            this->board_->placeBrick(*currentBrick_->getBrickModel(), *upperLeft);
            if (upperLeft->get_x() == 0) {
                updateState(GameState::FINISHED);
                Direction dir {-5, -5};
                *currentBrick_+dir;
            }

            auto linesCompleted = this->board_->getCompletedLines();
            this->board_->clearLines(linesCompleted);
            int numberLinesCompleted = linesCompleted.size();
            this->player_->increaseScore(numberLinesCompleted, difficulty_->getLevel(), vv.get_x());
            this->player_->increaseLinesCount(numberLinesCompleted);

            if (this->player_->getScore() >= this->difficulty_->getMaxScore() ||
                this->player_->getLinesCompleted() >= this->difficulty_->getMaxLines()) {
                this->difficulty_->nextDifficulty();
            }
            if(this->player_->getScore() >= this->difficulty_->getMaxScore() || this->player_->getLinesCompleted() >= this->difficulty_->getMaxLines()){
                    this->updateState(GameState::FINISHED);
            }
            if (this->gameState_ != GameState::FINISHED) {
                generate();
            }
            else{
                Direction dir {-100, -100};
                *currentBrick_+dir;
            }
            return false;
        }
        else if (!this->board_->isInside(vv)) {
            return false;
        }
        else if (!currentBrick_->canMove(this->board_->getBoard(), direction)) {
            return false;
        }
    }
    *currentBrick_+direction;

    return true;
}

void Game::update(bool clockwise)
{
    currentBrick_->rotation(*this->board_, clockwise);
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
    while (update(StaticDirections::DOWN)) {
    }

}

std::pair<Position, BrickModel> Game::getBrickDetails()
{
    return std::make_pair(*this->currentBrick_->getUpperLeft(),*this->currentBrick_->getBrickModel());
}

int Game::getScore() {
    return this->player_->getScore();
}

int Game::getLinesCompleted() {
    return this->player_->getLinesCompleted();
}

int Game::getTimeLimit() {
    return this->difficulty_->getTimeLimit();
}
