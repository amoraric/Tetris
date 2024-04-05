#include "BrickBag.h"

BrickBag::BrickBag() {
    brickBag_.push_back(StaticBrickModels::T);
    brickBag_.push_back(StaticBrickModels::L);
    brickBag_.push_back(StaticBrickModels::I);
    brickBag_.push_back(StaticBrickModels::J);
    brickBag_.push_back(StaticBrickModels::Z);
    brickBag_.push_back(StaticBrickModels::S);
    brickBag_.push_back(StaticBrickModels::O);
}

bool BrickBag::addBrick(const BrickModel& newBrick) {
    if (newBrick.model.size() != 4) {
        return false;
    }
    for (const auto& brick : brickBag_) {
        if (brick == newBrick) {
            return false; // TODO : check for rotation of the brickModel
        }
    }
    brickBag_.push_back(newBrick);
    return true;
}

std::vector<BrickModel> BrickBag::getBrickBag()
{
    return brickBag_;
}

void BrickBag::eraseBrickIndex(int index)
{
    brickBag_.erase(brickBag_.begin() + index);
}
