
#include "Bridge.h"

void Bridge::playerMove(int column) {
    m_connect4.makePlayerMove(column);
}

std::vector<int> Bridge::getValidLocations() const {
    return m_connect4.getValidLocations();
}

bool Bridge::isGameOver() {
    return m_connect4.isGameOver();
}

void Bridge::start() {
    m_connect4.start();
}

std::pair<bool, bool> Bridge::getWinnerPair() {
    return m_connect4.getWinner();
}

int Bridge::pieceAt(int row, int col) const {
    return m_connect4.pieceAt(row, col);
}

Connect4::RenderPieceSet Bridge::getWinningBoardPieces() const {
    return m_connect4.getWinningBoardPieces();
}

std::string Bridge::getStatus() const {
    return m_connect4.getStatus();
}
