
#include "Game.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::array;

void Game::run() {
    m_gameBridge.start();
    display();

    while(!m_gameBridge.isGameOver()) {
        playerTurn();
        display();
    }
    displayWinningBoard();
    auto winnerPair = m_gameBridge.getWinnerPair();
    if (winnerPair.first) {
        cout << "Human \033[1;32mPlayer X\033[0m WINS!!" << endl;
    } else if (winnerPair.second) {
        cout << "AI \033[1;32mPlayer O\033[0m WINS!!" << endl;
    } else {
        std::cout << "\n\nGame Over: DRAW\n\n" << std::endl;
    }
}

void Game::playerTurn() {
    int choice = promptHuman() - 1;
    m_gameBridge.playerMove(choice);
}

int Game::promptHuman() const {
    int choice = 0;
    while (true) {
        cout << "Enter Human X choice: ";
        cin >> choice;
        auto choices = m_gameBridge.getValidLocations();
        bool goodChoice = std::find(choices.begin(), choices.end(), (choice - 1)) != choices.end();
        if (cin.fail() || !goodChoice) {
            cin.clear();
            cin.ignore();
            cout << "Re-enter a valid value! " << endl;
        } else {
            break;
        }
    }
    return choice;
}

char getPiece(int piece) {
    if (piece == 1) {
        return 'X';
    } else if (piece == 2) {
        return 'O';
    } else {
        return ' ';
    }
}

void Game::display() {
    cout << "\n\n" << endl;
    for (int r = 0; r < 6; ++r) {
        std::cout << "| ";
        for (int c = 0; c < 7; ++c) {
            cout << getPiece(m_gameBridge.pieceAt(r, c)) << " | ";
        }
        cout << endl;
    }
    cout << " --- --- --- --- --- --- ---" << endl;
    cout << "  1   2   3   4   5   6   7  " << endl;
}

void Game::displayWinningBoard() {
    auto renderBoard = m_gameBridge.getWinningBoardPieces();
    std::cout << "\n\n" << std::endl;
    array<array<Connect4::RenderPiece, 7>, 6>::const_iterator row;
    for (row = renderBoard.begin(); row != renderBoard.end(); ++row) {
        std::cout << "| ";
        for (int c = 0; c < Board::COLUMN_COUNT; ++c) {
            drawRenderPiece(row->at(c));
        }
        std::cout << std::endl;
    }
    std::cout << " --- --- --- --- --- --- ---" << std::endl;
    std::cout << "  1   2   3   4   5   6   7  " << std::endl;
}

void Game::drawRenderPiece(Connect4::RenderPiece piece) const {
    if (piece.piece == Board::EMPTY_PIECE) {
        std::cout << ' ' << " | ";
    } else {
        if (piece.piece == Board::PLAYER_PIECE) {
            if (piece.isWinner) {
                std::cout << "\033[1;32mX\033[0m" << " | ";
            } else {
                std::cout << "X" << " | ";
            }
        } else {
            if (piece.isWinner) {
                std::cout << "\033[1;32mO\033[0m" << " | ";
            } else {
                std::cout << "O" << " | ";
            }
        }
    }
}