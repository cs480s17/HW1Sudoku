#include<iostream>
#include"Board.hpp"

using namespace std;

int main()
{
  short board[9][9] = {{0, 0, 0, 0, 0, 0, 2, 0, 0},
		       {0, 0, 0, 0, 0, 0, 0, 0, 0},
		       {8, 0, 0, 0, 0, 0, 0, 0, 0},
		       {0, 0, 0, 0, 0, 0, 8, 5, 0},
		       {0, 0, 0, 3, 0, 0, 0, 0, 0},
		       {0, 4, 1, 0, 0, 0, 0, 0, 0},
		       {0, 0, 0, 0, 0, 0, 0, 0, 0},
		       {0, 0, 0, 0, 0, 0, 0, 0, 5},
		       {5, 0, 4, 0, 0, 0, 0, 0, 0}};
  Board *b = new Board(board);
  bool array[9];
  b -> GetPossible(63, array);
  for(int i = 0; i < 9; i++)
    cout << array[i];
  cout << endl;
  b -> PrintBoard();
  
}
