#include <memory>
#include "Direction.h"
#include "Brick.h"
#include "Board.h"

Brick::Brick(BrickModel model, Board &board) : orientation_(0), model_(std::make_unique<BrickModel>(model)),
    upperLeft_(std::make_unique<Position>(board.getSize()/2, 0)), state_(BrickState::FALLING) {}

void Brick::rotation(bool clockwise)
{
    if (clockwise) { // 00 01 02 11 -> 01 10 11 21

    } else { // 00 10 20 30 -> 00 01 02 03

    } // 00 01 11 12 -> 00 10 11 21 -> 01 02 10 11
}

bool Brick::canMove(const Board &board, Direction direction) const
{
    std::vector<std::vector<bool>> currentBoard = board.getBoard();
    if (direction == StaticDirections::LEFT) {
        for (int i = 0; i < this->model_->model.size(); i++) {
            if (currentBoard[this->upperLeft_->get_x() + this->model_->model.at(i).get_x()-1][this->upperLeft_->get_y() + this->model_->model.at(i).get_y()]) {

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
