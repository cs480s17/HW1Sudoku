#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
int main()
{
  srand(time(NULL));
  for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
	{
	  int chance = rand() % 7;
	  if(chance != 0)
	    cout << 0 << " ";
	  else
	    cout << rand() % 9 + 1 << " ";
	  
	}
      cout << endl;
    }
  return 0;
}
