
#ifndef CONNECT4_BOARDSCOREHELPER_H
#define CONNECT4_BOARDSCOREHELPER_H

#include "Board.h"

class BoardScoreHelper {
public:
    void getHorizontalSets(Board::GameBoard const& board, std::vector<std::array<int, 4>> &pieceSets);

    void getVerticalSets(Board::GameBoard const& board, std::vector<std::array<int, 4>> &pieceSets);

    void getPositiveDiagonalSets(Board::GameBoard const& board, std::vector<std::array<int, 4>> &pieceSets);

    void getNegativeDiagonalSets(Board::GameBoard const& board, std::vector<std::array<int, 4>> &pieceSets);
};


#endif //CONNECT4_BOARDSCOREHELPER_H
