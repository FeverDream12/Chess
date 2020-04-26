#include "headerFile.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char playerMove[6];

    char board[9][9] = {{'1', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'8', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    BoardDraw(board);

    while (1)
    {
        move(playerMove, board);
        BoardDraw(board);
    }
    return 0;
}
