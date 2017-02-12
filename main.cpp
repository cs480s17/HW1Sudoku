#include<iostream>
#include"Board.hpp"

using namespace std;

int main()
{
  bool array[9];
  Board::GetPossible(21, array);
  for(int i = 0; i < 9; i++)
    cout << array[i];
  cout << endl;
  Board::PrintBoard();
  
}
