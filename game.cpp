/*
 *Max Shi
 *10/11/2021
 *This program allows two players to play tictactoe in the command line.
 */
#include <iostream>

using namespace::std;

void printGrid(int array[3][3]);

int main()
{
  bool play = true;
  while(play == true)
    {
      int grid[3][3] = {{0,1,0}, {0,0,2}, {1,0,0}};
      printGrid(grid);
      play = false;
    }
}

void printGrid(int array[3][3])
{
  cout << "  1 2 3" << endl;
  char row = 'a';
  for(int r = 0; r < 3; r++)
    {
      cout << row << " ";
      row++;
      for(int c = 0; c < 3; c++)
	{
	  switch(array[r][c])
	    {
	    case 0:
	      cout << "  ";
	      break;
	    case 1:
	      cout << "X ";
	      break;
	    case 2:
	      cout << "O ";
	      break;
	    default:
	      cout << "  ";
	    }
	}
      cout << "\n";
    }
}
