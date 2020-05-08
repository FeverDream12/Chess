#include "headerFile.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int Y_from = 0, Y_to = 0;
int X_from = 0, X_to = 0;
int Qualifier;

void move(char playerMove[], char board[][9])
{
    if (strlen(playerMove) == 5) {
        Qualifier = 0;
        if (CorrectInput(playerMove, board, Qualifier)) {
            PawnMove(board);
        }
    } else {
        Qualifier = 1;
        if (CorrectInput(playerMove, board, Qualifier)) {
            moveFigure(playerMove, board);
        }
    }
}

void PawnMove(char board[][9])
{
    if (board[Y_from - 1][X_from] == 'p') {
        board[Y_from - 1][X_from] = ' ';
        board[Y_to - 1][X_to] = 'p';
    } else if (board[Y_from - 1][X_from] == 'P') {
        board[Y_from - 1][X_from] = ' ';
        board[Y_to - 1][X_to] = 'P';
    } else {
        cout << "Error, this figure is not a pawn. Make a correct move" << endl
             << endl;
    }
}

void moveFigure(char playerMove[], char board[][9])
{
    if (board[Y_from - 1][X_from] == playerMove[0]) {
        board[Y_from - 1][X_from] = ' ';
        board[Y_to - 1][X_to] = playerMove[0];
    }
}

bool CorrectInput(char playerMove[], char board[][9], int Qualifier)
{
    string input = " ";

    switch (playerMove[0 + Qualifier]) {
    case 'a':
        X_from = 1;
        break;
    case 'b':
        X_from = 2;
        break;
    case 'c':
        X_from = 3;
        break;
    case 'd':
        X_from = 4;
        break;
    case 'e':
        X_from = 5;
        break;
    case 'f':
        X_from = 6;
        break;
    case 'g':
        X_from = 7;
        break;
    case 'h':
        X_from = 8;
        break;
    default: {
        cout << "Incorrect input" << endl << endl;
        return false;
    }; break;
    }

    switch (playerMove[3 + Qualifier]) {
    case 'a':
        X_to = 1;
        break;
    case 'b':
        X_to = 2;
        break;
    case 'c':
        X_to = 3;
        break;
    case 'd':
        X_to = 4;
        break;
    case 'e':
        X_to = 5;
        break;
    case 'f':
        X_to = 6;
        break;
    case 'g':
        X_to = 7;
        break;
    case 'h':
        X_to = 8;
        break;
    default: {
        cout << "Incorrect input" << endl << endl;
        return false;
    }; break;
    }

    input[0] = playerMove[1 + Qualifier];
    Y_from = atoi(input.c_str());

    input[0] = playerMove[4 + Qualifier];
    Y_to = atoi(input.c_str());

    if ((Y_from <= 0 || Y_from >= 9) || (X_from <= 0 || X_from >= 9)
        || (Y_to <= 0 || Y_to >= 9) || (X_to <= 0 || X_to >= 9)
        || (board[Y_from - 1][X_from] == ' ')) {
        cout << "Error. Incorrect input. Out of the board or empty cage."
             << endl;
        return false;
    }
    return true;
}
