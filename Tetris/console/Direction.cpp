#include "Direction.h"


Direction::Direction(int x, int y) : dx_{x}, dy_{y}
{}

int Direction::getDx() const
{
    return dx_;
}

int Direction::getDy() const
{
    return dy_;
}

bool Direction::operator==(const Direction& other) const {
    return this->dx_ == other.getDx() && this->dy_ == other.getDy();
}

namespace StaticDirections{
    const Direction LEFT{-1,0};
    const Direction RIGHT{1,0};
    const Direction DOWN{0,-1};
}
