#include<vector>
#include<iostream>
using namespace std;

const short totalrc = 9;

class Board
{
public:
  Board(short [totalrc][totalrc]);
  ~Board();
  void GetPossible(short, bool *);
  void PrintBoard();
  
private:
  short board[totalrc][totalrc];
  
};

Board::Board(short (input)[totalrc][totalrc])
{
  for(short i = 0; i < totalrc; i++)
    for(short j = 0; j < totalrc; j++)
      {
        short x= input[i][j];
	board[i][j] = x;
      }
}

void Board::GetPossible(short cell, bool *possible )
{
  short row = cell / totalrc;
  short col = cell % totalrc;
  for(int i = 0; i < totalrc; i++)
    possible[i] = true;
  
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
	    {
	      possible[currcell - 1] = 0;
	      //	      cout << "row: " << row << "col: " << col << endl;
	      //cout << "curr boxrow: " << boxrow+i <<"curr boxcol: "<<boxcol+j<<endl;
	    }
	}
    }
  return;
}
  
void Board::PrintBoard()
{
  cout << "-------------------------------------" << endl;
  for(short i = 0; i < totalrc; i++)
    {
      cout << "| ";
      for(short j = 0;  j < totalrc; j++)
	{
	  cout << board[i][j] << " | ";
	 
	}
      cout << endl;
      cout << "-------------------------------------" << endl;
    }
  return;
}
