#include "Position.h"

Position::Position(int x, int y) : coordinates_(std::make_pair(x, y)) {}

int Position::get_x() const { return coordinates_.first; }

int Position::get_y() const { return coordinates_.second; }

bool Position::operator==(const Position& other) const {
    return coordinates_ == other.coordinates_;
}

bool comparePositions(const Position &pos1, const Position &pos2)
{
    return (pos1.get_x() < pos2.get_x()) || ((pos1.get_x() == pos2.get_x()) && (pos1.get_y() < pos2.get_y()));
}
