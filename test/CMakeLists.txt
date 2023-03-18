message(STATUS "Building Unit Tests ${UNITTEST}")

set(connect_SRCS
        ../src/core/AiPlayer.cpp
        ../src/core/Board.cpp
        ../src/core/BoardScore.cpp
        ../src/core/BoardScoreHelper.cpp
        )

set(connect_ut_SRCS
        ${connect_SRCS}
        main.cpp
        BoardTest.cpp
        AiPlayerTest.cpp
        BoardScoreTest.cpp
        BoardScoreHelperTest.cpp)

add_executable(ConnectTest ${connect_ut_SRCS})
target_link_libraries(ConnectTest ${CONAN_LIBS} )
add_test(NAME ConnectTest COMMAND ConnectTest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
