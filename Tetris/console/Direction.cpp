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
    const Direction LEFT{0,-1};
    const Direction RIGHT{0,1};
    const Direction DOWN{1,0};
}
