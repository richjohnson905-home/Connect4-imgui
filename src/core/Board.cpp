
#include "Board.h"
#include "BoardScore.h"

using std::array;
using std::vector;

Board::Board(BoardScore* boardScore): m_pBoardScore(boardScore) {

    array<int, COLUMN_COUNT> row0 = {0,0,0,0,0,0,0};
    array<int, COLUMN_COUNT> row1 = {0,0,0,0,0,0,0};
    array<int, COLUMN_COUNT> row2 = {0,0,0,0,0,0,0};
    array<int, COLUMN_COUNT> row3 = {0,0,0,0,0,0,0};
    array<int, COLUMN_COUNT> row4 = {0,0,0,0,0,0,0};
    array<int, COLUMN_COUNT> row5 = {0,0,0,0,0,0,0};
    m_board = {row0, row1, row2, row3, row4, row5};
}

bool Board::isValidLocation(int col) const {
    return m_board.at(0).at(col) == EMPTY_PIECE;
}

vector<int> Board::getValidLocations() const {
    vector<int> validLocations;
    for (int c = 0; c < COLUMN_COUNT; ++c) {
        if (isValidLocation(c)) {
            validLocations.push_back(c);
        }
    }
    return validLocations;
}

void Board::dropPiece(int col, int piece) {
    std::array<std::array<int, COLUMN_COUNT>, ROW_COUNT>::reverse_iterator row;
    for (row = m_board.rbegin(); row != m_board.rend(); ++row) {
        if (row->at(col) == EMPTY_PIECE) {
            row->at(col) = piece;
            break;
        }
    }
}

int Board::scorePosition(int piece) const {
    int score = 0;

    score += m_pBoardScore->scoreCenterColumn(piece, m_board);
    score += m_pBoardScore->scoreHorizontalSets(piece, m_board, false);
    score += m_pBoardScore->scoreVerticalSets(piece, m_board, false);
    score += m_pBoardScore->scorePositiveDiagonalSets(piece, m_board, false);
    score += m_pBoardScore->scoreNegativeDiagonalSets(piece, m_board, false);

    return score;
}

bool Board::isWinningMove(int piece) const {
    if (m_pBoardScore->scoreHorizontalSets(piece, m_board, true) == 100) {
        return true;
    } else if (m_pBoardScore->scoreVerticalSets(piece, m_board, true) == 100) {
        return true;
    } else if (m_pBoardScore->scorePositiveDiagonalSets(piece, m_board, true) == 100) {
        return true;
    } else if (m_pBoardScore->scoreNegativeDiagonalSets(piece, m_board, true) == 100) {
        return true;
    } else {
        return false;
    }
}

int Board::pieceAt(int row, int col) const {
    return m_board.at(row).at(col);
}
