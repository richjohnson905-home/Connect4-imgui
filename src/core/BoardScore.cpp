
#include "BoardScore.h"
#include "BoardScoreHelper.h"

using std::array;
using std::vector;


BoardScore::BoardScore(BoardScoreHelper* helper): m_boardScoreHelper(helper) {

}

int BoardScore::evaluateSet(std::array<int, 4>& pieces, int piece) {
    int score = 0;
    int opp_piece = Board::PLAYER_PIECE;
    if (piece == Board::PLAYER_PIECE) {
        opp_piece = Board::AI_PIECE;
    }
    auto pieceCount = std::count(pieces.begin(), pieces.end(), piece);
    auto emptyCount = std::count(pieces.begin(), pieces.end(), (int)Board::EMPTY_PIECE);
    if (pieceCount == 4) {
        score += 100;
    } else if (pieceCount == 3 && emptyCount == 1) {
        score += 5;
    } else if (pieceCount == 2 && emptyCount == 2) {
        score += 2;
    }

    if ((std::count(pieces.begin(), pieces.end(), opp_piece) == 3) && emptyCount == 1) {
        score -= 10;
    }
    return score;
}

int BoardScore::scoreCenterColumn(int piece, Board::GameBoard const& board) {
    std::array<int, Board::ROW_COUNT> centerColumn = {
            board.at(0).at(3),
            board.at(1).at(3),
            board.at(2).at(3),
            board.at(3).at(3),
            board.at(4).at(3),
            board.at(5).at(3)};
    auto centerCount = std::count(centerColumn.begin(), centerColumn.end(), piece);
    return centerCount * 3;
}

int BoardScore::scoreHorizontalSets(int piece, Board::GameBoard const& board, bool breakOnWin) {
    vector<array<int, 4>> horizontalPieceSets;
    m_boardScoreHelper->getHorizontalSets(board, horizontalPieceSets);
    return doScoring(horizontalPieceSets, piece, breakOnWin);
}

int BoardScore::scoreVerticalSets(int piece, Board::GameBoard const& board, bool breakOnWin) {
    vector<array<int, 4>> verticalPieceSets;
    m_boardScoreHelper->getVerticalSets(board, verticalPieceSets);
    return doScoring(verticalPieceSets, piece, breakOnWin);
}

int BoardScore::scorePositiveDiagonalSets(int piece, Board::GameBoard const& board, bool breakOnWin) {
    vector<array<int, 4>> positiveDiagonalPieceSets;
    m_boardScoreHelper->getPositiveDiagonalSets(board, positiveDiagonalPieceSets);
    return doScoring(positiveDiagonalPieceSets, piece, breakOnWin);
}


int BoardScore::scoreNegativeDiagonalSets(int piece, Board::GameBoard const& board, bool breakOnWin) {
    vector<array<int, 4>> negativeDiagonalPieceSets;
    m_boardScoreHelper->getNegativeDiagonalSets(board, negativeDiagonalPieceSets);
    return doScoring(negativeDiagonalPieceSets, piece, breakOnWin);
}

int BoardScore::doScoring(vector<array<int, 4>> const& pieceSetVector, int piece, bool breakOnWin) {
    int score = 0;
    for (auto ps : pieceSetVector) {
        auto setScore = evaluateSet(ps, piece);
        if (breakOnWin && setScore == 100) {
            return 100;
        } else {
            score += setScore;
        }
    }
    return score;
}