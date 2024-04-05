#include "Board.h"
#include <cstdlib>

Board::Board(std::size_t rows, std::size_t columns) : board_{rows, std::vector<bool>(columns, false)} {}

bool Board::isInside(Position position)
{
    return position.get_x() >= 0 && position.get_x() < board_.size()
           && position.get_y() >= 0 && position.get_y() < board_[0].size();
}

void Board::clearLines(std::vector<int> completedLines)
{
    for (int i : completedLines) {
        board_.erase(board_.begin() + i);
        board_.insert(board_.begin(), std::vector<bool>(board_[0].size(), false));
    }
}

std::vector<int> Board::getCompletedLines()
{
    std::vector<int> completedLines;
    for (int i = 0; i < board_.size(); i++) {
        for (int j = 0; j < board_[0].size(); j++) {
            if (board_[i][j]) {
                if (j == board_[0].size()-1) {
                    completedLines.push_back(i);
                }
            } else {
                break;
            }

        }
    }
    return completedLines;
}

void Board::placeBrick(const BrickModel &brickModel, Position pos)
{
    if (!isInside(pos)) {
        return;
    }
    for (int i = 0; i < brickModel.model.size(); i++) {
        board_[brickModel.model[i].get_x() + pos.get_x()][brickModel.model[i].get_y() + pos.get_y()] = true;
    }
}

bool Board::isOccupied(Position pos) const
{
    return board_[pos.get_x()][pos.get_y()];
}

const std::vector<std::vector<bool> > Board::getBoard() const
{
    return board_;
}

void Board::randomize()
{
   auto randomBool = std::rand() % 2;
   for (int i = 0; i < 6; i++) {
       for (int j = 0; j < board_[0].size(); j++) {
           board_[i][j] = randomBool;
           randomBool = std::rand() % 2;
       }
    }
   for (int i = board_.size()-2; i >= 0; i--) {
       for (int j = 0; j < board_[0].size(); j++) {
           auto n = i+1;
           while(n<= board_.size()-1 && board_[n][j] == false && board_[n-1][j]){
                board_[n][j] = true;
                board_[n-1][j] = false;
                n++;
            }
       }
    }
   clearLines(this->getCompletedLines());
}

int Board::getSize()
{
    return board_.size();
}
