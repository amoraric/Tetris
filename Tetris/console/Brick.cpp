#include <memory>
#include "Direction.h"
#include "Brick.h"

Brick::Brick(BrickModel model, Board &board) : orientation_(0), model_(std::make_unique<BrickModel>(model)),
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
        for (int i = 0; i < this->model_->model.size(); i++) {
            if (currentBoard[this->upperLeft_->get_x() + this->model_->model.at(i).get_x()-1][this->upperLeft_->get_y() + this->model_->model.at(i).get_y()]) {

            }
        }
    } else if (direction == StaticDirections::RIGHT) {

    } else {

    }

}

BrickState Brick::getBrickState() {
    return state_;
}

std::unique_ptr<Position> Brick::getUpperLeft() {
    return std::make_unique<Position>(*upperLeft_);
}

std::unique_ptr<BrickModel> Brick::getShape() {
    return std::make_unique<BrickModel>(*model_);
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
