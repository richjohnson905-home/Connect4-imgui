

set(connect4core_SRCS
        AiPlayer.cpp
        Connect4.cpp
        Board.cpp
        BoardScore.cpp
        BoardScoreHelper.cpp
        Bridge.cpp)

add_library(connect4core STATIC ${connect4core_SRCS})


target_link_libraries(connect4core
        ${CONAN_LIBS}
        )