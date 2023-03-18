
#ifndef CONNECT4_CONNECT4_H
#define CONNECT4_CONNECT4_H

#include "AiPlayer.h"
#include "BoardScoreHelper.h"
#include "Board.h"
#include "Log.h"
#include "BoardScore.h"
#include <iostream>
#include <random>
#include <string>

class Connect4 {
private:
    bool aiTurn();

    Board m_board;
    BoardScore m_boardScore;
    BoardScoreHelper m_boardScoreHelper;
    AiPlayer m_ai;
    bool m_isGameOver;
    bool m_isHumanWinner;
    bool m_isAiWinner;
    std::string m_status;

public:
    struct RenderPiece {
        bool isWinner;
        int piece;
    };

    typedef std::array<std::array<Connect4::RenderPiece, Board::COLUMN_COUNT>, Board::ROW_COUNT> RenderPieceSet;

    Connect4();

    void start();
    void makePlayerMove(int column);
    int getValidLocationsSize();
    std::vector<int> getValidLocations() const;
    bool isGameOver();
    std::pair<bool, bool> getWinner();
    int pieceAt(int row, int col) const;
    RenderPieceSet getWinningBoardPieces() const;
    std::string getStatus() const;

    template <typename Prob = double>
    bool getRandomBool(const Prob p = 0.5) {
        static auto dev = std::random_device();
        static auto gen = std::mt19937{dev()};
        static auto dist = std::uniform_real_distribution<Prob>(0,1);
        return (dist(gen) < p);
    }
};


#endif //CONNECT4_CONNECT4_H
