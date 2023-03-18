
#include "AiPlayer.h"
#include <random>
#include <iostream>
#include "Log.h"

bool AiPlayer::isTerminalNode(Board const &board) const {
    return board.isWinningMove(Board::PLAYER_PIECE) ||
           board.isWinningMove(Board::AI_PIECE) ||
           board.getValidLocations().size() == 0;
}

std::pair<int, int> AiPlayer::minimax(
        Board const &board,
        int depth,
        int alpha,
        int beta,
        bool maximizingPlayer) const {
    L_(ldebug2) << "AiPlayer::minimax";
    auto validLocations = board.getValidLocations();
    auto isTerminal = isTerminalNode(board);
    if (depth == 0 || isTerminal) {
        if (isTerminal) {
            if (board.isWinningMove(Board::AI_PIECE)) {
                L_(linfo) << "AI WINNER";
                return std::make_pair(0, INT_MAX);
            } else if (board.isWinningMove(Board::PLAYER_PIECE)) {
                L_(linfo) << "HUMAN WINNER";
                return std::make_pair(0, INT_MIN);
            } else {
                // game is over, no more valid moves
                return std::make_pair(0, 0);
            }
        } else {
            // depth is zero
            auto theScore = board.scorePosition(Board::AI_PIECE);
            L_(ldebug2) << "Depth Zero THE SCORE: " << theScore;
            return std::make_pair(0, theScore);
        }
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(validLocations.begin(), validLocations.end(), g);
    if (maximizingPlayer) {
        auto bestValue = INT_MIN;
        auto randomColumn = *(validLocations.begin());
        for (auto c : validLocations) {
            L_(ldebug) << "MAX NODE: " << c + 1;
            Board boardCopy = board;
            boardCopy.dropPiece(c, Board::AI_PIECE);
            auto newScore = minimax(boardCopy, depth - 1, alpha, beta, false).second;
            if (newScore > bestValue) {
                bestValue = newScore;
                randomColumn = c;
            }
            alpha = std::max(alpha, bestValue);
            if (beta <= alpha) {
                L_(ldebug) << "Max SNIP " << alpha << "=>" << beta << " Column: " << randomColumn + 1;
                break;
            } else {
                L_(ldebug) << "Max not pruning " << alpha << "!=>" << beta << " Column: " << randomColumn + 1;
            }
        }
        L_(ldebug) << "Done Max col: " << randomColumn + 1 << " Score: " << bestValue << " Depth: " << depth;
        return std::make_pair(randomColumn, bestValue);
    } else {
        // minimizing player
        auto bestValue = INT_MAX;
        auto randomColumn = *(validLocations.begin());
        for (auto c : validLocations) {
            L_(ldebug1) << "MIN NODE: " << c + 1;
            Board boardCopy = board;
            boardCopy.dropPiece(c, Board::PLAYER_PIECE);
            auto newScore = minimax(boardCopy, depth - 1, alpha, beta, true).second;
            if (newScore < bestValue) {
                bestValue = newScore;
                randomColumn = c;
            }
            beta = std::min(beta, bestValue);
            if (beta <= alpha) {
                L_(ldebug2) << "Min SNIP " << alpha << "=>" << beta << " Column: " << randomColumn + 1;
                break;
            } else {
                L_(ldebug2) << "Min NOT pruning " << alpha << "!>=" << beta << " Column: " << randomColumn + 1;
            }
        }
        L_(ldebug1) << "Done Min col: " << randomColumn + 1 << " Score: " << bestValue << " Depth: " << depth;
        return std::make_pair(randomColumn, bestValue);
    }
}