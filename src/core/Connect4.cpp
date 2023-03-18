
#include "Connect4.h"
#include "Log.h"
#include <sstream>

using std::array;
using std::stringstream;

Connect4::Connect4():
m_boardScore(&m_boardScoreHelper),
m_board(&m_boardScore),
m_isGameOver(false),
m_isAiWinner(false),
m_isHumanWinner(false),
m_status(""){

}

void Connect4::start() {
    bool aiPlayerStart = getRandomBool();
    if (aiPlayerStart) {
        m_isGameOver = aiTurn();
    }
}

bool Connect4::aiTurn() {
    L_(linfo) << "Connect4::aiTurn";
    auto col = m_ai.minimax(m_board, 3, INT_MIN, INT_MAX, true).first;
    stringstream ss;
    ss << "AI Choice: " << col + 1;
    m_status = ss.str();
    if (m_board.isValidLocation(col)) {
        m_board.dropPiece(col, Board::AI_PIECE);
        if (m_board.isWinningMove(Board::AI_PIECE)) {
            m_isAiWinner = true;
            m_status = "Good game! Play Again?";
            return true;
        }
    }
    return false;
}

void Connect4::makePlayerMove(int column) {
    if (m_board.isValidLocation(column)) {
        m_board.dropPiece(column, Board::PLAYER_PIECE);
        if (m_board.isWinningMove(Board::PLAYER_PIECE)) {
            m_status = "Damn Human, you finally beat me LOL!";
            m_isHumanWinner = true;
            m_isGameOver = true;
        } else {
            m_isGameOver = aiTurn();
        }
    }
}

int Connect4::getValidLocationsSize() {
    return m_board.getValidLocations().size();
}

std::vector<int> Connect4::getValidLocations() const {
    return m_board.getValidLocations();
}

bool Connect4::isGameOver() {
    bool draw = m_board.getValidLocations().size() == 0;
    return m_isGameOver || draw;
}

std::pair<bool, bool> Connect4::getWinner() {
    return std::pair<bool, bool>{m_isHumanWinner, m_isAiWinner};
}

int Connect4::pieceAt(int row, int col) const {
    return m_board.pieceAt(row, col);
}

bool allEqual(array<int, 4> & pieceSet) {
    return (pieceSet.at(0) == pieceSet.at(1)) &&
        (pieceSet.at(0) == pieceSet.at(2)) &&
        (pieceSet.at(0) == pieceSet.at(3));
}

Connect4::RenderPieceSet Connect4::getWinningBoardPieces() const {
    auto gameBoard = m_board.getGameBoard();
    int x = 0;
    int y = 0;
    RenderPieceSet renderBoard{};

    // create render pieces
    for (int r = 0; r < Board::ROW_COUNT; ++r) {
        for (int c = 0; c < Board::COLUMN_COUNT; ++c) {
            RenderPiece rp;
            rp.isWinner = false;
            rp.piece = gameBoard->at(r).at(c);
            renderBoard.at(r).at(c) = rp;
        }
    }

    // check horizontal
    for (int r = 0; r < Board::ROW_COUNT; ++r) {
        for (int c = 0; c < Board::COLUMN_COUNT - 3; ++c) {
            std::array<int, 4> pieceSet = {
                    gameBoard->at(r).at(c),
                    gameBoard->at(r).at(c + 1),
                    gameBoard->at(r).at(c + 2),
                    gameBoard->at(r).at(c + 3)};
            if (gameBoard->at(r).at(c) != Board::EMPTY_PIECE) {
                if (allEqual(pieceSet)) {
                    renderBoard.at(r).at(c).isWinner = true;
                    renderBoard.at(r).at(c + 1).isWinner = true;
                    renderBoard.at(r).at(c + 2).isWinner = true;
                    renderBoard.at(r).at(c + 3).isWinner = true;
                    break;
                }
            }
        }
    }
    // vertical
    for (int c = 0; c < Board::COLUMN_COUNT; ++c) {
        for (int r = 0; r < Board::ROW_COUNT - 3; ++r) {
            std::array<int, 4> pieceSet = {
                    gameBoard->at(r).at(c),
                    gameBoard->at(r + 1).at(c),
                    gameBoard->at(r + 2).at(c),
                    gameBoard->at(r + 3).at(c)};
            if (gameBoard->at(r).at(c) != Board::EMPTY_PIECE) {
                if (allEqual(pieceSet)) {
                    renderBoard.at(r).at(c).isWinner = true;
                    renderBoard.at(r + 1).at(c).isWinner = true;
                    renderBoard.at(r + 2).at(c).isWinner = true;
                    renderBoard.at(r + 3).at(c).isWinner = true;
                    break;
                }
            }
        }
    }
    for (int c = 0; c < Board::COLUMN_COUNT - 3; ++c) {
        for (int r = 0; r < Board::ROW_COUNT - 3; ++r) {
            std::array<int, 4> pieceSet = {
                    gameBoard->at(r).at(c),
                    gameBoard->at(r + 1).at(c + 1),
                    gameBoard->at(r + 2).at(c + 2),
                    gameBoard->at(r + 3).at(c + 3)};
            if (gameBoard->at(r).at(c) != Board::EMPTY_PIECE) {
                if (allEqual(pieceSet)) {
                    renderBoard.at(r).at(c).isWinner = true;
                    renderBoard.at(r + 1).at(c + 1).isWinner = true;
                    renderBoard.at(r + 2).at(c + 2).isWinner = true;
                    renderBoard.at(r + 3).at(c + 3).isWinner = true;
                    break;
                }
            }
        }
    }
    for (int r = 3; r < Board::ROW_COUNT; ++r) {
        for (int c = 0; c < Board::COLUMN_COUNT - 3; ++c) {
            std::array<int, 4> pieceSet = {
                    gameBoard->at(r).at(c),
                    gameBoard->at(r - 1).at(c + 1),
                    gameBoard->at(r - 2).at(c + 2),
                    gameBoard->at(r - 3).at(c + 3)};
            if (gameBoard->at(r).at(c) != Board::EMPTY_PIECE) {
                if (allEqual(pieceSet)) {
                    renderBoard.at(r).at(c).isWinner = true;
                    renderBoard.at(r - 1).at(c + 1).isWinner = true;
                    renderBoard.at(r - 2).at(c + 2).isWinner = true;
                    renderBoard.at(r - 3).at(c + 3).isWinner = true;
                    break;
                }
            }
        }
    }
    return renderBoard;
}

std::string Connect4::getStatus() const {
    return m_status;
}

