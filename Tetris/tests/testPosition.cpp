#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "Position.h"

TEST_CASE("the 2 positions are identical", "[identical]") {
    Position p1(1, 2);
    Position p2(1, 2);
    REQUIRE((p1 == p2) == true);
}
