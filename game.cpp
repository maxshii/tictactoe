/*
 *Max Shi
 *10/13/2021
 *This program allows two players to play tictactoe in the command line.
 */
#include <iostream>
#include <cctype>
#include <limits>

using namespace::std;

void printGrid(int **array);

void getMove(int **array, int player);

int main()
{
  bool play = true;
  int player = 1;
  int playerOneWin = 0;
  int playerTwoWin = 0;
  while(play == true)
    {
      int grid[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
      int **ptrGrid = new int*[3];
      for (int i = 0; i < 3; i++)
	{
	  ptrGrid[i] = new int[3];  
	for (int j = 0; j < 3; j++)
	  {
	  ptrGrid[i][j] = grid[i][j];
	  }
	}
      
      while(true) {
	printGrid(ptrGrid);
	cout << "Player " << player << " move: " << endl;
	getMove(ptrGrid, player);
	//printGrid(ptrGrid);

	if(player == 1)
	  {
	    player = 2;
	  }
	else
	  {
	    player = 1;
	  }
      
      }
    }
}

void printGrid(int **array)
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
	    case 1: //player 1 is X
	      cout << "X ";
	      break;
	    case 2: //player 2 is O
	      cout << "O ";
	      break;
	    default:
	      cout << "  ";
	    }
	}
      cout << "\n";
    }
}

//gets an input and checks if it is a legal move
void getMove(int **array, int player)
{
  char input[4];
  while(true) {
    cout << "Enter move: row,column" << endl;
    if (cin >> input)
      {
	//checks if format is row,column
	if (isalpha(input[0]) != true && input[1] != ',' && isdigit(input[2]) != true) 
	  {
	    cout << "Wrong format" << endl;
	    continue;
	    }

	//turns the input into variables that can be used in the array
	int row = (int)input[0] - 97;
        int col = (int)input[2] - 49;

	//checks if the input is in the grid
	if((0 <= row && row < 3  && 0 <= col && col < 3) != true) 
	   {
	     cout << "Your input is not in the grid" << endl;
	     continue;
	   }

	//checks if inputted space is taken
	if(array[row][col] != 0) 
	  {
	    cout << "This space is already taken" << endl;
	    continue;
	  }

	array[row][col] = player;
        break;
      }
    else
      {
	cout << "Use format: row,column" << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
  }
}
