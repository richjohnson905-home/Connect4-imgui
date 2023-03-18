
#include "Game.h"
#include <iostream>

int main() {

    FILELog::ReportingLevel() = linfo;
    initLogger("connect4.log", linfo);
    L_(linfo) << "Connect 4 Start up";

    Game game;
    game.run();

    return 0;
}
