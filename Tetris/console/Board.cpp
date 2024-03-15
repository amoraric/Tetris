#include "Board.h"

Board::Board(size_t rows, size_t columns) : board_{rows, std::vector<bool>(columns, false)} {}

bool Board::isInside(Position position)
{
    return position.get_x() >= 0 && position.get_x() < board_.size()
           && position.get_y() >= 0 && position.get_y() <= board_[0].size();
}

void Board::clearLines(std::vector<int> completedLines)
{
    for (int i : completedLines) {
        board_.erase(board_.begin() + i);
        board_.insert(board_.begin(), std::vector<bool>(board_.size(), false));
    }
}

std::vector<int> Board::getCompletedLines()
{
    std::vector<int> completedLines;
    for (int i = 0; i < board_[0].size(); i++) {
        for (int j = 0; j < board_.size(); j++) {
            if (board_[i][j]) {
                if (j == board_.size()-1) {
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

std::vector<std::vector<bool> > Board::getBoard()
{
    return board_;
}

int Board::getSize()
{
    return board_.size();
}
