#include<iostream>
#include"Board.hpp"
#include<stack>
#include<fstream>
#include<string>

using namespace std;
Board solve(stack<Board>&);

int main(int argc, char *argv[])
{
	string path;
	cout << "supply file name: ";
    cin >> path;
    const char* file = path.c_str();
    ifstream in(file);
    cin.rdbuf(in.rdbuf());
    
    short board[9][9];
    short s;
    
    int m = 0;
    int row = 0;
    int col = 0;
    while(cin >> s)
    {
        row = m/ 9;
        col = m%9;
        m++;
        board[row][col] = s;
    }
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
  
