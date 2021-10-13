/*
 *Max Shi
 *10/13/2021
 *This program allows two players to play tictactoe in the command line.
 */
#include <iostream>
#include <cctype>
#include <limits>

using namespace::std;

void printGrid(int array[3][3]);

void getMove(int** array[3][3], int player);

int main()
{
  bool play = true;
  int player = 1;
  while(play == true)
    {
      int grid[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
      char input[3];
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

void getMove(int** array[3][3], int player)
{
  char input[4];
  while(true) {
    cout << "Enter move (row,column)" << endl;
    if (cin >> input)
      {
	if (isalpha(input[0]) && input[1] == ',' && isdigit(input[2]))
	  {
	    int row = (int)input[0] - 97;
	    int col = (int)input[2] - 49;

	    **array[row][col] = player;
	    break;
	  }
	else
	  {
	    cout << "Use format (row,column)" << endl;
	  }
      }
    else
      {
	cout << "Use format (row,column)" << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
  }
}
