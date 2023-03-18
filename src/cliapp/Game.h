
#ifndef CONNECT4_GAME_H
#define CONNECT4_GAME_H

#include "../core/Bridge.h"

class Game {
private:
    Bridge m_gameBridge;

    void playerTurn();
    int promptHuman() const;
    void display();
    void displayWinningBoard();
    void drawRenderPiece(Connect4::RenderPiece piece) const;
public:
    void run();
};

#endif //CONNECT4_GAME_H
