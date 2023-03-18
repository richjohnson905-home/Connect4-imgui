#include <catch2/catch.hpp>
#include "../src/core/AiPlayer.h"
#include "../src/core/BoardScoreHelper.h"
#include "../src/core/BoardScore.h"
#include "../src/core/Log.h"

using std::array;

TEST_CASE("scenario1 block opponent in column 0") {
    FILELog::ReportingLevel() = ldebug;
    Board::GameBoard gameBoard;

    gameBoard = {{
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 2, 0, 0, 0},
                     {1, 0, 0, 2, 2, 0, 0},
    }};
    BoardScoreHelper helper;
    BoardScore boardScore(&helper);
    Board board(&boardScore);
    board.testBoardSet(gameBoard);


    AiPlayer testObject;
    auto p = testObject.minimax(board, 2, INT_MIN, INT_MAX, true);
    REQUIRE(0 == p.first);
}

TEST_CASE("scenario2 block opponent in column 6") {
    FILELog::ReportingLevel() = linfo;
    Board::GameBoard gameBoard;

    gameBoard = {{
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 1},
                     {0, 0, 0, 2, 0, 0, 1},
                     {0, 0, 0, 2, 2, 0, 1},
    }};
    BoardScoreHelper helper;
    BoardScore boardScore(&helper);
    Board board(&boardScore);
    board.testBoardSet(gameBoard);
    AiPlayer testObject;
    auto p = testObject.minimax(board, 2, INT_MIN, INT_MAX, true);
    REQUIRE(6 == p.first);
}

TEST_CASE("scenario3 should not enable opponent win in column 2") {
    FILELog::ReportingLevel() = ldebug1;
    Board::GameBoard gameBoard;

    gameBoard = {{
                     {0, 1, 0, 1, 2, 1, 2},
                     {0, 2, 0, 2, 2, 2, 1},
                     {1, 1, 0, 2, 1, 1, 1},
                     {2, 2, 0, 1, 1, 2, 2},
                     {1, 2, 0, 2, 2, 1, 1},
                     {2, 1, 0, 2, 1, 2, 1},
    }};
    BoardScoreHelper helper;
    BoardScore boardScore(&helper);
    Board board(&boardScore);
    board.testBoardSet(gameBoard);
    AiPlayer testObject;
    auto p = testObject.minimax(board, 2, INT_MIN, INT_MAX, true);
    REQUIRE(0 == p.first);
}