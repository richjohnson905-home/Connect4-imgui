
message(STATUS "Building Connect4 Cli App")

set(Main_SRCS
        main.cpp
        Game.cpp
        )

add_executable(connect4CliApp
        ${Main_SRCS}
        )

target_include_directories(connect4CliApp PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Connect4_SOURCE_DIR}/include
        )

# Specify here the libraries this program depends on
target_link_libraries(connect4CliApp
        connect4core
        )