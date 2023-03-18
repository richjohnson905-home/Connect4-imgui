
#ifndef CONNECT4_BRIDGE_H
#define CONNECT4_BRIDGE_H

#include "Connect4.h"

class Bridge {
private:
    Connect4 m_connect4;
public:
    void start();
    void playerMove(int column);
    std::vector<int> getValidLocations() const;
    bool isGameOver();
    std::pair<bool, bool> getWinnerPair();
    int pieceAt(int row, int col) const;
    Connect4::RenderPieceSet getWinningBoardPieces() const;
    std::string getStatus() const;

};


#endif //CONNECT4_BRIDGE_H
