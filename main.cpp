#include<iostream>
#include"Board.hpp"

using namespace std;

int main()
{
  Board b;
  bool array[9];
  b.GetPossible(63, array);
  for(int i = 0; i < 9; i++)
    cout << array[i];
  cout << endl;
  b.PrintBoard();
  
}
