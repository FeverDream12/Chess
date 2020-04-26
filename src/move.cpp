#include "headerFile.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

int Y_from = 0, Y_to = 0;
int X_from = 0, X_to = 0;

void move(char playerMove[], char board[][9])
{
  if(CorrectInput(playerMove, board))
  {
    PawnMove(board);
  }
}

void PawnMove(char board[][9])
{
  if (board[Y_from - 1][X_from] == 'p')
  {
      board[Y_from - 1][X_from] = ' ';
      board[Y_to - 1][X_to] = 'p';
  }
  else if (board[Y_from - 1][X_from] == 'P')
  {
      board[Y_from - 1][X_from] = ' ';
      board[Y_to - 1][X_to] = 'P';
  }
}

bool CorrectInput(char playerMove[], char board[][9])
{
  string input = " ";
  cout << "Make a move :" << endl;
  cin >> playerMove;
  cout << endl;

  switch (playerMove[0])
  {
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
  }

  switch (playerMove[3])
  {
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
  }

  input[0] = playerMove[1];
  Y_from = atoi(input.c_str());

  input[0] = playerMove[4];
  Y_to = atoi(input.c_str());

  if((Y_from <= 0 || Y_from >= 9) || (X_from <= 0 || X_from >= 9) || (Y_to <= 0 || Y_to >= 9) || (X_to <= 0 || X_to >= 9))
  {
    cout << "Error. Incorrect input. Out of the board." << endl;
    return false;
  }
  return true;
}
