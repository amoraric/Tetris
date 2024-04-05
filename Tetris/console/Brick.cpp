#include <memory>
#include "Direction.h"
#include "Brick.h"

Brick::Brick(BrickModel model, Board &board) : orientation_(0), brickModel_(std::make_unique<BrickModel>(model)),
    upperLeft_(std::make_unique<Position>(0, board.getBoard()[0].size()/2)), state_(BrickState::FALLING) {}

void Brick::rotation(const Board& board, bool clockwise)
{
    std::vector<Position> currentBrick = brickModel_->model;
    std::vector<Position> originalBrick = currentBrick;

    std::vector<std::vector<int>> rotationMatrix;
    if (clockwise)
        rotationMatrix = {{0, 1}, {-1, 0}};
    else
        rotationMatrix = {{0, -1}, {1, 0}};

    for (size_t i = 0; i < currentBrick.size(); ++i) {
        int x = currentBrick[i].get_x();
        int y = currentBrick[i].get_y();
        int newX = rotationMatrix[0][0] * x + rotationMatrix[0][1] * y;
        int newY = rotationMatrix[1][0] * x + rotationMatrix[1][1] * y;
        currentBrick[i] = Position(newX, newY);
    }

    if (canRotate(board, currentBrick)) {
        brickModel_->model = currentBrick;
    }

    // if (clockwise) { // 00 01 02 11 -> 01 10 11 21

    // } else { // 00 10 20 30 -> 00 01 02 03

    // } // 00 01 11 12 -> 00 10 11 21 -> 01 02 10 11
}

bool Brick::canMove(const Board &board, Direction direction)
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

bool Brick::canRotate(const Board& board, const std::vector<Position>& brick) const
{
    auto currentBoard = board.getBoard();
    for (const auto& position : brick) {
        int newX = upperLeft_->get_x() + position.get_x();
        int newY = upperLeft_->get_y() + position.get_y();
        if (newX < 0 || newX >= currentBoard.size() || newY < 0 || newY >= currentBoard[0].size() ||
            currentBoard[newX][newY]) {
            return false;
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
