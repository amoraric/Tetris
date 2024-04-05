#include "Board.h"
#include <iostream>
#include "Brick.h"
#include "BrickBag.h"
#include "Difficulty.h"
#include "Controller.h"

int main() {
    // Create some BrickModels
//    BrickModel brick1;
//    brick1.model.push_back(Position(0, 0));
//    brick1.model.push_back(Position(0, 1));
//    brick1.model.push_back(Position(1, 0));
//    brick1.model.push_back(Position(1, 0));

//    BrickModel brick2;
//    brick2.model.push_back(Position(1, 0));
//    brick2.model.push_back(Position(1, 0));
//    brick2.model.push_back(Position(0, 1));
//    brick2.model.push_back(Position(0, 0));

//    BrickModel brick3;
//    brick3.model.push_back(Position(0, 0));
//    brick3.model.push_back(Position(1, 1));
//    brick3.model.push_back(Position(1, 0));
//    brick3.model.push_back(Position(1, 0));

//    BrickModel brick4;
//    brick4.model.push_back(Position(0, 0));
//    brick4.model.push_back(Position(1, 1));
//    brick4.model.push_back(Position(1, 0));

//    // Create a BrickBag
//    BrickBag bag;

//    // Add bricks to the bag
//    std::cout << "Adding brick1 to bag: " << (bag.addBrick(brick1) ? "Success" : "Failed") << std::endl;
//    std::cout << "Adding brick2 to bag: " << (bag.addBrick(brick2) ? "Success" : "Failed") << std::endl;
//    std::cout << "Adding brick3 to bag: " << (bag.addBrick(brick3) ? "Success" : "Failed") << std::endl;
//    std::cout << "Adding brick4 to bag: " << (bag.addBrick(brick4) ? "Success" : "Failed") << std::endl;

//    Board board {20, 10};
//    board.getBoard()[0][1] = true;
//    for (int var = 0; var < board.getSize(); ++var) {
//        for (int j = 0; j < board.getBoard()[0].size(); ++j) {
//            std::cout<<board.getBoard()[var][j];

//        }
//        std::cout<<std::endl;

//    }

//    std::cout << board.getBoard().size() << " : " << board.getBoard()[0].size() << std::endl;
//    try{
//        Difficulty diff(1);
//        std::cout << diff.getMaxLines() << std::endl;

//    }
//    catch(std::exception e){
//        std::cout<< "game over";
//    }

//    // Controller c;
//    // c.start();

    auto cc = std::make_shared<Controller>();
    cc->start();

    return 0;
}
