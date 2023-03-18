#include <catch2/catch.hpp>
#include "../src/core/BoardScore.h"
#include "../src/core/BoardScoreHelper.h"

using std::array;
using std::vector;


TEST_CASE("evaluate empty set") {
    BoardScoreHelper helper;
    BoardScore testObject(&helper);
    array<int, 4> pieceSet = {0, 0, 0, 0};
    REQUIRE(0 == testObject.evaluateSet(pieceSet, 1));
}

TEST_CASE("evaluate connect4 set") {
    BoardScoreHelper helper;
    BoardScore testObject(&helper);
    array<int, 4> pieceSet = {1, 1, 1, 1};
    REQUIRE(100 == testObject.evaluateSet(pieceSet, 1));
}

TEST_CASE("evaluate 3 set") {
    BoardScoreHelper helper;
    BoardScore testObject(&helper);
    array<int, 4> pieceSet = {1, 1, 1, 0};
    REQUIRE(5 == testObject.evaluateSet(pieceSet, 1));
}

TEST_CASE("evaluate 2 set") {
    BoardScoreHelper helper;
    BoardScore testObject(&helper);
    array<int, 4> pieceSet = {1, 1, 0, 0};
    REQUIRE(2 == testObject.evaluateSet(pieceSet, 1));
}

TEST_CASE("evaluate block opponent set") {
    BoardScoreHelper helper;
    BoardScore testObject(&helper);
    array<int, 4> pieceSet = {2, 2, 2, 0};
    REQUIRE(-10 == testObject.evaluateSet(pieceSet, 1));
}

TEST_CASE("score center column") {
    BoardScoreHelper helper;
    BoardScore testObject(&helper);
    array<int, Board::COLUMN_COUNT> row0 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row1 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row2 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row3 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row4 = {0,0,0,1,1,1,1};
    array<int, Board::COLUMN_COUNT> row5 = {0,0,0,1,1,1,1};
    array<array<int, Board::COLUMN_COUNT>, Board::ROW_COUNT> columns = {row0, row1, row2, row3, row4, row5};

    REQUIRE(6 == testObject.scoreCenterColumn(1, columns));
}