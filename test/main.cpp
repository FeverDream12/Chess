#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "../src/headerFile.h"
#include "../thirdparty/catch.hpp"
#include <string>
using namespace std;

char board[9][9] = {{'1', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                   {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {'8', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                   {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

TEST_CASE("Move_Pawn", "Correct")
{
    int Qualifier = 0;
    char playerMove[6] = "e2-e4";
    REQUIRE(CorrectInput( playerMove,board,Qualifier) == true);
}
