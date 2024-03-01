#include <memory>
#include "Direction.h"

Brick::Brick(BrickModel s, Board &board) : orientation_(0), shape_(std::make_unique<BrickModel>(s)),
    upperLeft_(std::make_unique<Position>(&board.board_.size()/2, 0)), state_(BrickState::FALLING) {}

void Brick::rotation(bool clockwise)
{
    if (clockwise) { // 00 01 02 11 -> 01 10 11 21

    } else { // 00 10 20 30 -> 00 01 02 03

    } // 00 01 11 12 -> 00 10 11 21 -> 01 02 10 11
}

bool Brick::canMove(const Board &board, Direction direction) const
{
    if (direction == StaticDirections::LEFT) {
        for (int i = 0; i < this->shape_.model_.size(); i++) {
            if (board.board_[this->upperLeft_.getX() + this->shape_.model_.at(i).getDx()-1][this->upperLeft_.getY() + this->shape_.model_.at(i).getDy()]) {

            }
        }
    } else if (direction == StaticDirections::RIGHT) {

    } else {

    }
}

bool Brick::canRotate(const Board &board) const
{

}

BrickState Brick::getBrickState()
{

}

std::unique_ptr<Position> Brick::getUpperLeft()
{

}

std::unique_ptr<BrickModel> Brick::getShape()
{

}

void Brick::operator+(Direction direction)
{

}
