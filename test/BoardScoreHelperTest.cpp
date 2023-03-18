#include <catch2/catch.hpp>

#include "../src/core/BoardScoreHelper.h"

using std::array;
using std::vector;

TEST_CASE("get all horizontal sets") {
    BoardScoreHelper testObject;
    array<int, Board::COLUMN_COUNT> row0 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row1 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row2 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row3 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row4 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row5 = {0,0,0,0,1,1,1};
    array<array<int, Board::COLUMN_COUNT>, Board::ROW_COUNT> columns = {row0, row1, row2, row3, row4, row5};

    vector<array<int, 4>> pieceSets;
    testObject.getHorizontalSets(columns, pieceSets);
    REQUIRE(24 == pieceSets.size());
}

TEST_CASE("get all vertical sets") {
    BoardScoreHelper testObject;
    array<int, Board::COLUMN_COUNT> row0 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row1 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row2 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row3 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row4 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row5 = {0,0,0,0,1,1,1};
    array<array<int, Board::COLUMN_COUNT>, Board::ROW_COUNT> columns = {row0, row1, row2, row3, row4, row5};

    vector<array<int, 4>> pieceSets;
    testObject.getVerticalSets(columns, pieceSets);
    REQUIRE(21 == pieceSets.size());
}

TEST_CASE("get positive diagonal sets") {
    BoardScoreHelper testObject;
    array<int, Board::COLUMN_COUNT> row0 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row1 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row2 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row3 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row4 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row5 = {0,0,0,0,1,1,1};
    array<array<int, Board::COLUMN_COUNT>, Board::ROW_COUNT> columns = {row0, row1, row2, row3, row4, row5};

    vector<array<int, 4>> pieceSets;
    testObject.getPositiveDiagonalSets(columns, pieceSets);
    REQUIRE(12 == pieceSets.size());
}

TEST_CASE("get negative diagonal sets") {
    BoardScoreHelper testObject;
    array<int, Board::COLUMN_COUNT> row0 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row1 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row2 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row3 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row4 = {0,0,0,0,1,1,1};
    array<int, Board::COLUMN_COUNT> row5 = {0,0,0,0,1,1,1};
    array<array<int, Board::COLUMN_COUNT>, Board::ROW_COUNT> columns = {row0, row1, row2, row3, row4, row5};

    vector<array<int, 4>> pieceSets;
    testObject.getNegativeDiagonalSets(columns, pieceSets);
    REQUIRE(12 == pieceSets.size());
}
