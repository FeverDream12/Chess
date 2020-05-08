#define CATCH_CONFIG_MAIN
#include "../src/headerFile.h"
#include "../thirdparty/catch.hpp"
#include <string>
using namespace std;

char board[9][9]
        = {{'1', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'8', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
           {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

TEST_CASE("PawnMove_1", "Correct pawn move")
{
    int Qualifier = 0;
    char playerMove[6] = "e2-e4";
    REQUIRE(CorrectInput(playerMove, board, Qualifier) == true);
}

TEST_CASE("PawnMove_2", "Incorrect pawn move")
{
    int Qualifier = 0;
    char playerMove[6] = "c8-c9";
    REQUIRE(CorrectInput(playerMove, board, Qualifier) == false);
}

TEST_CASE("CorrectFigureMove", "Correct")
{
    int Qualifier = 1;
    char playerMove[7] = "Bc8-c6";
    REQUIRE(CorrectInput(playerMove, board, Qualifier) == true);
}

TEST_CASE("IncorrectFigureMove", "Incorrect")
{
    int Qualifier = 1;
    char playerMove[7] = "Qc8-c9";
    REQUIRE(CorrectInput(playerMove, board, Qualifier) == false);
}

TEST_CASE("MoveFigure_1", "Incorrect move outside of the board")
{
    int Qualifier = 1;
    char playerMove[7] = "Qd0-d3";
    REQUIRE(CorrectInput(playerMove, board, Qualifier) == false);
}

TEST_CASE("MoveFigure_2", "Incorrect move outside of the board")
{
    int Qualifier = 1;
    char playerMove[7] = "Bd9-d3";
    REQUIRE(CorrectInput(playerMove, board, Qualifier) == false);
}

TEST_CASE("MoveFigure_3", "Incorrect move from empty cage")
{
    int Qualifier = 1;
    char playerMove[7] = "Nd6-d4";
    REQUIRE(CorrectInput(playerMove, board, Qualifier) == false);
}

TEST_CASE("IncorrectMoveInput", "Incorrect move input")
{
    int Qualifier = 1;
    char playerMove[7] = "Nd6-i8";
    REQUIRE(CorrectInput(playerMove, board, Qualifier) == false);
}
