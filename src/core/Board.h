
#ifndef CONNECT4_BOARD_H
#define CONNECT4_BOARD_H

#include <array>
#include <vector>

class BoardScore;

class Board {
public:
    static int const ROW_COUNT = 6;
    static int const COLUMN_COUNT = 7;
    static int const PLAYER_PIECE = 1;
    static int const AI_PIECE = 2;
    static int const EMPTY_PIECE = 0;

    typedef std::array<std::array<int, COLUMN_COUNT>, ROW_COUNT> GameBoard;

private:
    BoardScore *m_pBoardScore;
    GameBoard m_board{};


public:
    explicit Board(BoardScore *pBoardScore);

    bool isValidLocation(int col) const;
    std::vector<int> getValidLocations() const;
    bool isWinningMove(int piece) const;
    int scorePosition(int piece) const;
    GameBoard const* getGameBoard() const {return &m_board;}
    int pieceAt(int row, int col) const;

    void dropPiece(int col, int piece);


    void testBoardSet(GameBoard const& board){m_board = board;}
};

#endif //CONNECT4_BOARD_H
