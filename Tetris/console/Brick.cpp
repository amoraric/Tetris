#include <memory>
#include "Direction.h"
#include "Brick.h"

Brick::Brick(BrickModel model, Board &board) : orientation_(0), brickModel_(std::make_unique<BrickModel>(model)),
    upperLeft_(std::make_unique<Position>(board.getSize()/2, 0)), state_(BrickState::FALLING) {}

void Brick::rotation(bool clockwise)
{
    if (clockwise) { // 00 01 02 11 -> 01 10 11 21

    } else { // 00 10 20 30 -> 00 01 02 03

    } // 00 01 11 12 -> 00 10 11 21 -> 01 02 10 11
}

bool Brick::canMove(Board &board, Direction direction)
{
    auto currentBoard = board.getBoard();
    if (direction == StaticDirections::LEFT) {
        for (int i = 0; i < this->brickModel_->model.size(); i++) {
            if (currentBoard[this->upperLeft_->get_x() + this->brickModel_->model.at(i).get_x()-1][this->upperLeft_->get_y() + this->brickModel_->model.at(i).get_y()]) {
                return false;
            }
        }
    } else if (direction == StaticDirections::RIGHT) {
        for (int i = 0; i < this->brickModel_->model.size(); i++) {
            if (currentBoard[this->upperLeft_->get_x() + this->brickModel_->model.at(i).get_x()+1][this->upperLeft_->get_y() + this->brickModel_->model.at(i).get_y()]) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < this->brickModel_->model.size(); i++) {
            if (currentBoard[this->upperLeft_->get_x() + this->brickModel_->model.at(i).get_x()][this->upperLeft_->get_y() + this->brickModel_->model.at(i).get_y()+1]) {
                return false;
            }
        }
    }
    return true;
}

BrickState Brick::getBrickState() {
    return state_;
}

std::unique_ptr<Position> Brick::getUpperLeft() {
    return std::make_unique<Position>(*upperLeft_);
}

std::unique_ptr<BrickModel> Brick::getBrickModel() {
    return std::make_unique<BrickModel>(*brickModel_);
}

void Brick::operator+(Direction direction)
{
    int currentX = upperLeft_->get_x();
    int currentY = upperLeft_->get_y();

    int dx = direction.getDx();
    int dy = direction.getDy();

    currentX += dx;
    currentY += dy;

    upperLeft_ = std::make_unique<Position>(currentX, currentY);    
}
