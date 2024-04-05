#include <memory>
#include "Direction.h"
#include "Brick.h"
#include <iostream>

Brick::Brick(BrickModel model, const Board &board) : orientation_(0), brickModel_(std::make_unique<BrickModel>(model)),
    upperLeft_(std::make_unique<Position>(0, board.getBoard()[0].size()/2)), state_(BrickState::FALLING) {
    // calculates the center around which the brick is going to rotate
    int sumX = 0, sumY = 0;
    for (const auto& pos : brickModel_->model) {
        sumX += pos.get_x();
        sumY += pos.get_y();
    }
    int centerX = sumX / brickModel_->model.size();
    int centerY = sumY / brickModel_->model.size();
    center_ = std::make_unique<Position>((centerX + board.getBoard()[0].size() % 2), centerY);
}

void Brick::rotation(const Board& board, bool clockwise)
{
    // Checking if the brick is a square and not rotating it
    BrickModel O_temp {{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }};
    if (*this->brickModel_ == O_temp) {
        return;
    }

    std::vector<Position> currentBrick = brickModel_->model;
    std::vector<Position> originalBrick = currentBrick;

    std::cout << center_->get_x() << ":" << center_->get_y() << std::endl;

    std::vector<std::vector<int>> rotationMatrix;
    if (clockwise)
        rotationMatrix = {{0, 1}, {-1, 0}};
    else
        rotationMatrix = {{0, -1}, {1, 0}};

    // Applying rotation around the center point
    for (size_t i = 0; i < currentBrick.size(); ++i) {
        int x = currentBrick[i].get_x() - center_->get_x();
        int y = currentBrick[i].get_y() - center_->get_y();
        int newX = rotationMatrix[0][0] * x + rotationMatrix[0][1] * y;
        int newY = rotationMatrix[1][0] * x + rotationMatrix[1][1] * y;
        currentBrick[i] = Position(newX + center_->get_x(), newY + center_->get_y());
    }


    if (canRotate(board, currentBrick)) {
        brickModel_->model = currentBrick;
    } else {
        brickModel_->model = originalBrick;
    }
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
