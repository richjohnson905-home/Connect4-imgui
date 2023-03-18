
#include "BoardScoreHelper.h"


void BoardScoreHelper::getHorizontalSets(Board::GameBoard const& board, std::vector<std::array<int, 4>> &pieceSets) {
    for (int r = 0; r < Board::ROW_COUNT; ++r) {
        for (int c = 0; c < Board::COLUMN_COUNT - 3; ++c) {
            std::array<int, 4> pieceSet = {
                    board.at(r).at(c),
                    board.at(r).at(c + 1),
                    board.at(r).at(c + 2),
                    board.at(r).at(c + 3)};
            pieceSets.push_back(pieceSet);
        }
    }
}

void BoardScoreHelper::getVerticalSets(Board::GameBoard const& board, std::vector<std::array<int, 4>> &pieceSets) {
    for (int c = 0; c < Board::COLUMN_COUNT; ++c) {
        for (int r = 0; r < Board::ROW_COUNT - 3; ++r) {
            std::array<int, 4> pieceSet = {
                    board.at(r).at(c),
                    board.at(r + 1).at(c),
                    board.at(r + 2).at(c),
                    board.at(r + 3).at(c)};
            pieceSets.push_back(pieceSet);
        }
    }
}

void BoardScoreHelper::getPositiveDiagonalSets(Board::GameBoard const& board, std::vector<std::array<int, 4>> &pieceSets) {
    for (int c = 0; c < Board::COLUMN_COUNT - 3; ++c) {
        for (int r = 0; r < Board::ROW_COUNT - 3; ++r) {
            std::array<int, 4> pieceSet = {
                    board.at(r).at(c),
                    board.at(r + 1).at(c + 1),
                    board.at(r + 2).at(c + 2),
                    board.at(r + 3).at(c + 3)};
            pieceSets.push_back(pieceSet);
        }
    }
}

void BoardScoreHelper::getNegativeDiagonalSets(Board::GameBoard const& board, std::vector<std::array<int, 4>> &pieceSets) {
    for (int r = 3; r < Board::ROW_COUNT; ++r) {
        for (int c = 0; c < Board::COLUMN_COUNT - 3; ++c) {
            std::array<int, 4> pieceSet = {
                    board.at(r).at(c),
                    board.at(r - 1).at(c + 1),
                    board.at(r - 2).at(c + 2),
                    board.at(r - 3).at(c + 3)};
            pieceSets.push_back(pieceSet);
        }
    }
}