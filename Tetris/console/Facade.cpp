#include "Facade.h"

Game*Facade::game() const
{
    return game_.get();
}

std::string Facade::getNickname()
{
    return this->game_->getNickname();
}

int Facade::getLevel()
{
    return this->game_->getLevel();
}

Facade::Facade(std::string nickname, int level, int rows, int columns) : game_{std::make_unique<Game>(nickname,level,rows,columns)}
{}

Facade::~Facade()
{}

void Facade::end()
{
    this->game_->updateState(GameState::FINISHED);
}

void Facade::translation(Direction direction)
{
    if(game_->getGameState() == GameState::READY){
        this->game_->update(direction);
        notifyObservers();
    }
}

void Facade::rotation(bool clockwise)
{
    if(game_->getGameState() == GameState::READY){
        this->game_->update(clockwise);
        notifyObservers();
    }
}

void Facade::drop()
{
    if(game_->getGameState() == GameState::READY){
        this->game_->drop();
        notifyObservers();
    }
}

void Facade::addObserver(std::shared_ptr<Observer> observer)
{
    observers_.insert(observer);
}

void Facade::removeObserver(std::shared_ptr<Observer> observer)
{
    observers_.erase(observer);
}

void Facade::notifyObservers()
{
    for (auto o : observers_) {
       o->update();
    }
}

std::pair<Position, BrickModel> Facade::getBrickDetails()
{
    return this->game_->getBrickDetails();
}

bool Facade::isGameOver()
{
    return game_->getGameState() == GameState::FINISHED;
}

int Facade::getScore()
{
    return this->game_->getScore();
}

int Facade::getLinesCompleted()
{
    return this->game_->getLinesCompleted();
}

int Facade::getTimeLimit() {
    return this->game_->getTimeLimit();
}
