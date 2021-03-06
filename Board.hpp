#include<vector>
#include<iostream>
#include<stack>
using namespace std;

const short totalrc = 9;

class Board
{
public:
  bool PushChildren(stack<Board> &);
  bool GetPossible(short, bool *);
  void PrintBoard();
  Board&operator = (const Board&rhs);
  void Set(int row, int col, int val);
  Board(short [totalrc][totalrc]);
  ~Board(){}
  Board(){}
private:
  short board[totalrc][totalrc];
  
};



Board& Board::operator = (const Board&rhs)
{
  for(int i = 0; i < totalrc; i++)
    for(int j = 0; j < totalrc; j++)
      board[i][j] = rhs.board[i][j];
  return *this;
}

bool Board::PushChildren(stack<Board> &fringe)
{//pushes the children to the stack, returns false if the board is complete.
  bool is_complete = true;
  int least_branch_factor = 999;
  int least_index = 0;
  bool possible[totalrc];
  bool temp[totalrc];
  for(int i = 0; i < (totalrc * totalrc); i++)
    {
      if(GetPossible(i, temp))
	{
	  is_complete = false; //the cell is empty
	  int temp_branch_factor = 0;
	  for(int j = 0; j < totalrc; j++)//find number of possible entries
	    {
	      if(temp[j])
		{
		  temp_branch_factor++;
		}
	    }
	  if(temp_branch_factor < least_branch_factor)
	    {
	      least_branch_factor = temp_branch_factor;
	      least_index = i;//store the index of the best so far
	      for(int j = 0; j < totalrc; j++)//copy temp into possible
		{
		  possible[j] = temp[j];
		}
	    }
	}
    }
  if(is_complete)
    {
      return false; //This is a solution to the sudoku problem
    }
  //we have the index and possible from the best next cell
  short row = least_index / totalrc;
  short col = least_index % totalrc;
  //Board * tempBoard;
  for(int i = 0; i < totalrc; i++)
    {
      if(possible[i])
	{
	  //make a copy of the Board object
	  //tempBoard = new Board(board);
	  Board b = Board(board);
	  //change the designated cell to i
	  b.Set(row,col,i+1);
	  //need a function to do this ^^^
	  //push the Board to the stack
	  fringe.push(b);
	  //...make sure I'm not overwriting previous pushed boards
	  //...figure out if the stack can be a stack of boards, or a stack of pointers to boards

	}
    }
  return true; //Wasn't complete, children pushed if present
}
Board::Board(short (input)[totalrc][totalrc])
{
  for(short i = 0; i < totalrc; i++)
    for(short j = 0; j < totalrc; j++)
      {
        short x= input[i][j];
	board[i][j] = x;
      }
}

void Board::Set(int row, int col, int val)
{
  board[row][col] = val;
}

bool Board::GetPossible(short cell, bool *possible )
{
  short row = cell / totalrc;
  short col = cell % totalrc;
  if(board[row][col] > 0)
    {
      return false;
    }
  for(short i = 0; i < totalrc; i++)
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
  return true;
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
