
#ifndef CONNECT4_BOARDSCORE_H
#define CONNECT4_BOARDSCORE_H

#include "Board.h"

class BoardScoreHelper;

class BoardScore {
private:
    BoardScoreHelper* m_boardScoreHelper;

    int doScoring(std::vector<std::array<int, 4>> const& pieceSet, int piece, bool breakOnWin);

public:
    BoardScore(BoardScoreHelper* helper);

    int evaluateSet(std::array<int, 4>& pieces, int piece);
    int scoreCenterColumn(int piece, Board::GameBoard const& board);
    int scoreHorizontalSets(int piece, Board::GameBoard const& board, bool breakOnWin);
    int scoreVerticalSets(int piece, Board::GameBoard const& board, bool breakOnWin);
    int scorePositiveDiagonalSets(int piece, Board::GameBoard const& board, bool breakOnWin);
    int scoreNegativeDiagonalSets(int piece, Board::GameBoard const& board, bool breakOnWin);
};


#endif //CONNECT4_BOARDSCORE_H
