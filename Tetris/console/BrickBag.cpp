#include "BrickBag.h"

BrickBag::BrickBag() {}

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


std::vector<BrickModel> getBrickBag(){

}
// 00 01 02 11

// 01 10 11 12
