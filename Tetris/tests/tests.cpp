#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "Position.h"
#include "BrickBag.h"
#include "Board.h"
#include "Direction.h"
#include "Player.h"
#include "Brick.h"
#include "Board.h"
#include <iostream>
// Tests For Class Position
TEST_CASE("The 2 positions are identical", "[Positions identical]") {
    Position p1(1, 2);
    Position p2(1, 2);
    REQUIRE(p1 == p2);
}

TEST_CASE("The 2 positions are different", "[Positions different]") {
    Position p1(1, 2);
    Position p2(1, 3);
    REQUIRE((p1 == p2) == false);
}
//====================================================================

//Tests For Class Direction
TEST_CASE("The 2 directions are identical" ,"[Directions identical]"){
    Direction d1 {1,2};
    Direction d2 {1,2};
    REQUIRE(d1==d2);
}
TEST_CASE("The 2 directions are different" ,"[Directions different]"){
    Direction d1 {1,2};
    Direction d2 {1,3};
    REQUIRE((d1==d2) == false);
}
//=======================================================================

//Tests for Class BrickBag
TEST_CASE("Brick succesfully removed", "[removed]") {
    BrickBag b {};
    auto size = b.getBrickBag().size();
    b.eraseBrickIndex(3);
    REQUIRE(b.getBrickBag().size() == size-1);
}
//=====================================================

//Tests for class Brick
TEST_CASE("Brick can't move", "[Can't move]") {
    Board b {10,10};
    Brick brick {StaticBrickModels::O,b};
    Position p {1,6};
    b.placeBrick(StaticBrickModels::O,p);
    REQUIRE(brick.canMove(b,StaticDirections::DOWN) == false);
}
TEST_CASE("Brick can move", "[Can move]") {
    Board b {10,10};
    Brick brick {StaticBrickModels::O,b};
    Position p {2,6};
    b.placeBrick(StaticBrickModels::O,p);
    REQUIRE(brick.canMove(b,StaticDirections::DOWN));
}
TEST_CASE("Upper Left changed correctly ", "[Upper left correct]") {
    Board b {10,10};
    Brick brick {StaticBrickModels::O,b};
    brick+StaticDirections::DOWN;
    REQUIRE(*brick.getUpperLeft() == Position {1,5} );
}
//==============================================================

//Tests for class Board
TEST_CASE("Position is inside board", "[Is inside]") {
    Board b {10,10};
    Position p {2,2};
    REQUIRE(b.isInside(p));
}
TEST_CASE("Detection of completed lines", "[Detection completed lines]") {
    Board b {2,4};
    Position p {0,0};
    Position p2 {0,2};
    b.placeBrick(StaticBrickModels::O,p);
    b.placeBrick(StaticBrickModels::O,p2);
    REQUIRE(b.getCompletedLines().size() == 2);
}

TEST_CASE("Clears completed lines", "[Clear completed lines]") {
    Board b {2,4};
    Position p {0,0};
    Position p2 {0,2};
    b.placeBrick(StaticBrickModels::O,p);
    b.placeBrick(StaticBrickModels::O,p2);
    b.clearLines(b.getCompletedLines());
    REQUIRE(b.getCompletedLines().size() == 0);
}

TEST_CASE("Brick placed at expected positions", "[Brick placed correctly]") {
    Board b {10,10};
    Position p {5,5};
    b.placeBrick(StaticBrickModels::O,p);
    REQUIRE((b.getBoard()[5][5] && b.getBoard()[5][6] && b.getBoard()[6][5] && b.getBoard()[6][6]));
}

TEST_CASE("Position is occupied", "[Position occupied]") {
    Board b {10,10};
    Position p {5,5};
    b.placeBrick(StaticBrickModels::O,p);
    REQUIRE(b.isOccupied(p));
}

TEST_CASE("Randomize leaves no lines", "[Randomize clears lines]") {
    Board b {100,50};
    b.randomize();
    REQUIRE(b.getCompletedLines().size() == 0);
}
//====================================================================

//Tests For player
TEST_CASE("Scored increased properly", "[Score increase]") {
    Player p {"whatever"};
    p.increaseScore(0,2,8);
    REQUIRE(p.getScore() == 16);

}
//==========================================================


