#include "BrickModel.h"
#include "Position.h"
#include <algorithm>

bool BrickModel::operator==(const BrickModel& other) const {
    auto sortedBrick1 = this->model;
    auto sortedBrick2 = other.model;
    std::sort(sortedBrick1.begin(),sortedBrick1.end(),comparePositions);
    std::sort(sortedBrick2.begin(),sortedBrick2.end(),comparePositions);
    return sortedBrick1 == sortedBrick2;
}
