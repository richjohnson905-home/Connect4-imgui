#include <catch2/catch.hpp>

#include <array>

using std::array;

// NEED MOCKING TODO

TEST_CASE("score position opening board is zero") {
    array<array<int, 7>, 6> board;

    board = {{
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
    }};
//    REQUIRE(0 == scorePosition(1, board));
}

TEST_CASE("score position with center column having 2 pieces has score 8") {
    array<array<int, 7>, 6> board;

    board = {{
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0, 0},
                     {2, 0, 2, 1, 0, 2, 0},
    }};
//    REQUIRE(8 == scorePosition(1, board));
}

TEST_CASE("score position with non-center column having 2 pieces has score 2") {
    array<array<int, 7>, 6> board;

    board = {{
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 1, 0, 0, 0, 0, 0},
                     {2, 1, 2, 0, 0, 2, 0},
    }};
//    REQUIRE(2 == scorePosition(1, board));
}

TEST_CASE("score position with 3 vertical scores 5") {
    array<array<int, 7>, 6> board;

    board = {{
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {2, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0},
                     {1, 0, 2, 0, 0, 2, 0},
    }};
//    REQUIRE(7 == scorePosition(1, board));
}