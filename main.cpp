#include<iostream>
#include"Board.hpp"
#include<stack>

using namespace std;
Board solve(stack<Board>&);

int main()
{
  short board[9][9] = {{1, 0, 7, 0, 0, 0, 2, 0, 0},
		       {2, 0, 6, 0, 0, 0, 0, 0, 0},
		       {8, 3, 5, 0, 0, 0, 0, 0, 0},
		       {0, 0, 0, 0, 0, 0, 8, 5, 0},
		       {0, 0, 0, 3, 0, 0, 0, 0, 0},
		       {0, 0, 1, 0, 0, 0, 0, 0, 0},
		       {0, 0, 0, 0, 0, 0, 0, 0, 0},
		       {0, 0, 0, 0, 0, 0, 0, 0, 5},
		       {5, 0, 4, 0, 0, 0, 0, 0, 0}};
  Board b = Board(board);
  bool array[9];
  b.GetPossible(63, array);
  for(int i = 0; i < 9; i++)
    cout << array[i];
  cout << endl;
  b.PrintBoard();
  stack<Board> fringe;
  fringe.push(b);
  Board solution;
  solution = solve(fringe);
  cout << "Solution found, printing..." << endl;
  solution.PrintBoard();
  return 0;  
}

Board solve(stack<Board> &fringe)
{
  Board b;
  b = fringe.top();
  fringe.pop();
  if(b.PushChildren(fringe))
    {
      if(fringe.empty())
	{
	  cout << "No Solution, the last state was: " << endl;
	  b.PrintBoard();
	  cout << "Terminating" << endl;
	  exit(1);
	}
      else
	{
	  return solve(fringe);
	}
    }
  else
    {
      return b;
    }
}
  
