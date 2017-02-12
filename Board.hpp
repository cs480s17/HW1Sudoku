#include<vector>
#include<iostream>
using namespace std;

const int totalrc = 9;
short board[9][9] = {{0, 0, 0, 0, 0, 0, 2, 0, 0},
		     {0, 0, 0, 0, 0, 0, 0, 0, 0},
		     {8, 0, 0, 0, 0, 0, 0, 0, 0},
		     {0, 0, 0, 0, 0, 0, 8, 5, 0},
		     {0, 0, 0, 3, 0, 0, 0, 0, 0},
		     {0, 4, 1, 0, 0, 0, 0, 0, 0},
		     {0, 0, 0, 0, 0, 0, 0, 0, 0},
		     {0, 0, 0, 0, 0, 0, 0, 0, 5},
		     {5, 0, 4, 0, 0, 0, 0, 0, 0}};
class Board
{
public:
  Board();
  void GetPossible(short, bool *);
  void PrintBoard();

private:
  
};



void Board::GetPossible(short cell, bool *possible )
{
  short row = cell / totalrc;
  short col = row % totalrc;
  possible = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  
  for(short i = 0; i < totalrc; i++)
    {
      short currcell = board[i][col];
      if(currcell > 0)
	  possible[currcell - 1] = 0;
    }

  for(short i = 0; i < totalrc; i++)
    {
      short currcell = board[row][i];
      if(currcell > 0)
	  possible[currcell - 1] = 0;
    }

  short boxrow = row/3;
  short boxcol = col/3;
  boxrow *= 3;
  boxcol *= 3;
  for(short i = 0; i < 3; i++)
    {
      for(short j = 0; j < 3; j++)
	{
	  short currcell = board[boxrow+i][boxcol+j];
	  if(currcell > 0)
	    possible[currcell - 1] = 0;
	}
    }
  return;
}
  
void Board::PrintBoard()
{
  for(short i = 0; i < totalrc; i++)
    {
      cout << "  -  -  -  -  -  -  -  -  -  " << endl;
      cout << "| ";
      for(short j = 0;  j < totalrc; j++)
	{
	  cout << board[i][j] << " | ";
	}
    }
  cout << "  -  -  -  -  -  -  -  -  -  " << endl;
  return;
}