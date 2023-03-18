
#ifndef CONNECT4_CONNECT4APP_H
#define CONNECT4_CONNECT4APP_H

#include "AppBase.h"
#include "../core/Bridge.h"
#include <memory>

class Connect4App : public AppBase<Connect4App> {
private:
    static std::unique_ptr<Bridge> m_gameBridge;
    static int m_mouse_x;
    static int m_mouse_y;
    static bool m_gameOver;
    static std::string m_status;

public:
    Connect4App(){}
    ~Connect4App() = default;

    virtual void startup();
    virtual void update();

    static void drawCell(int row, int col);
    static void drawWinningCell(int row, int col, Connect4::RenderPiece piece);
    static void drawColumn(int col);

    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
};


#endif //CONNECT4_CONNECT4APP_H
