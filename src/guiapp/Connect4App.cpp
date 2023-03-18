
#include "Connect4App.h"
#include <iostream>

using std::cout;
using std::endl;
using std::array;
using std::unique_ptr;
using std::make_unique;

unique_ptr<Bridge> Connect4App::m_gameBridge = make_unique<Bridge>();
bool Connect4App::m_gameOver = false;
int Connect4App::m_mouse_x = 0;
int Connect4App::m_mouse_y = 0;
std::string Connect4App::m_status = "Let's start!";

void Connect4App::startup() {
    m_gameBridge->start();
}

void Connect4App::update() {
    m_status = m_gameBridge->getStatus();
    ImGui::Begin("Let's Play Connect4!");
    ImGui::Text(m_status.c_str(), 0);
    if (ImGui::Button("Restart"))  {
        m_gameBridge.reset(new Bridge());
        m_gameOver = false;
        m_status = "Let's Go!";
    }                           
                
    ImGui::End();
    if (m_gameBridge->isGameOver()) {
        m_gameOver = true;
        auto renderBoard = m_gameBridge->getWinningBoardPieces();
        for (int row = 0; row < 6; ++row) {
            for (int col = 0; col < 7; ++col) {
                drawWinningCell(row, col, renderBoard.at(row).at(col));
            }
        }
    } else {
        for (int row = 0; row < 6; ++row) {
            for (int col = 0; col < 7; ++col) {
                drawCell(row, col);
            }
        }
        for (int col = 0; col < 7; ++col) {
            drawColumn(col);
        }
    }
}

void Connect4App::drawColumn(int col) {
    float cellWidth = 100;
    float cellHeight = cellWidth * 6;

    ImVec2 topLeft = ImVec2(cellWidth * col, 0);
    ImVec2 bottomRight = ImVec2(cellWidth * (col + 1), cellHeight);
    ImDrawList* draw = ImGui::GetBackgroundDrawList();

    if (m_mouse_x > topLeft.x && m_mouse_x < bottomRight.x && m_mouse_y > topLeft.y && m_mouse_y < bottomRight.y) {
        draw->AddRect(topLeft, bottomRight, ImGui::GetColorU32(ImGuiCol_Text), 0.0f, 0, 4.0);
    }
}

void Connect4App::drawWinningCell(int row, int col, Connect4::RenderPiece piece) {
    float cellWidth = 100.0;
    float cellHeight = cellWidth;

    // Draw Grid
    ImVec2 topLeft = ImVec2(cellWidth * col, cellHeight * row);
    ImVec2 bottomRight = ImVec2(cellWidth * (col + 1), cellHeight * (row + 1));

    ImDrawList* draw = ImGui::GetBackgroundDrawList();
    draw->AddRect(topLeft, bottomRight, ImGui::GetColorU32(ImGuiCol_Text));

    float symbolSize = 75.0;
    ImVec2 center = ImVec2(cellWidth/2 + topLeft.x, cellHeight/2 + topLeft.y);
    draw->AddCircle(center, symbolSize/2, ImGui::GetColorU32(ImGuiCol_Text));

    if (piece.piece == 1) {
        draw->AddCircleFilled(center, symbolSize/2, IM_COL32(0, 0, 200, 255));
    } else if (piece.piece == 2) {
        draw->AddCircleFilled(center, symbolSize/2, IM_COL32(200, 0, 0, 255));
    } // else nothing
    float winnerSymbolSize = 10;
    if (piece.isWinner) {
        m_status = "Play Again?";
        draw->AddCircleFilled(center, winnerSymbolSize/2, IM_COL32(0, 0, 0, 255));
    }
}

void Connect4App::drawCell(int row, int col) {
    float cellWidth = 100;
    float cellHeight = cellWidth;

    // Draw Grid
    ImVec2 topLeft = ImVec2(cellWidth * col, cellHeight * row);
    ImVec2 bottomRight = ImVec2(cellWidth * (col + 1), cellHeight * (row + 1));

    ImDrawList* draw = ImGui::GetBackgroundDrawList();
    draw->AddRect(topLeft, bottomRight, ImGui::GetColorU32(ImGuiCol_Text));

    float symbolSize = 75;
    ImVec2 center = ImVec2(cellWidth/2 + topLeft.x, cellHeight/2 + topLeft.y);
    draw->AddCircle(center, symbolSize/2, ImGui::GetColorU32(ImGuiCol_Text));

    if (m_gameBridge->pieceAt(row, col) == 1) {
        draw->AddCircleFilled(center, symbolSize/2, IM_COL32(0, 0, 200, 255));
    } else if (m_gameBridge->pieceAt(row, col) == 2) {
        draw->AddCircleFilled(center, symbolSize/2, IM_COL32(200, 0, 0, 255));
    } // else nothing
}

void Connect4App::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    ImGuiIO& io = ImGui::GetIO();
    if (!io.WantCaptureMouse) {
        if (button == 0 && action == 1) {
            cout << "clicked button" << endl;
        } else if (button == 0 && action == 0) {
            if (!m_gameOver) {
                if (m_mouse_x < 100) {
                    m_gameBridge->playerMove(0);
                } else if (m_mouse_x < 200) {
                    m_gameBridge->playerMove(1);
                } else if (m_mouse_x < 300) {
                    m_gameBridge->playerMove(2);
                } else if (m_mouse_x < 400) {
                    m_gameBridge->playerMove(3);
                } else if (m_mouse_x < 500) {
                    m_gameBridge->playerMove(4);
                } else if (m_mouse_x < 600) {
                    m_gameBridge->playerMove(5);
                } else if (m_mouse_x < 700) {
                    m_gameBridge->playerMove(6);
                }
            }
        }
    }
}

void Connect4App::CursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    ImGuiIO& io = ImGui::GetIO();
    if (!io.WantCaptureMouse) {
        m_mouse_x = static_cast<int>(xpos);
        m_mouse_y = static_cast<int>(ypos);
    }
}