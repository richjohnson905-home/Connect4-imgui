
#ifndef CONNECT4_AIPLAYER_H
#define CONNECT4_AIPLAYER_H

#include "Board.h"
#include <array>
#include <climits>

class AiPlayer {
public:
    [[nodiscard]]
    bool isTerminalNode(Board const &board) const;

    [[nodiscard]]
    std::pair<int, int> minimax(Board const &board,
                int depth,
                int alpha,
                int beta,
                bool maximizingPlayer) const;
};


#endif //CONNECT4_AIPLAYER_H
