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

int checkWin(int **array);

int main()
{
  int playerOneWin = 0;
  int playerTwoWin = 0;
  while(true)
    {
      int player = 1;
      int move = 0;
      int grid[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}}; //player 1 is shown as X and represented by 1, player 2 is shown as O and represented as 2
      int **ptrGrid = new int*[3];
      for (int i = 0; i < 3; i++)
	{
	  ptrGrid[i] = new int[3];  
	for (int j = 0; j < 3; j++)
	  {
	  ptrGrid[i][j] = grid[i][j];
	  }
	}
      printGrid(ptrGrid);

      //keeps inputting moves until board is filled or someone wins
      while(true) {
	cout << "Player " << player << " move: " << endl;
	getMove(ptrGrid, player);
	move++;
	printGrid(ptrGrid);
	
	if(checkWin(ptrGrid) == 1)
	  {
	    cout << "Player 1 wins" << endl;
	    playerOneWin++;
	    break;
	  }
	else if(checkWin(ptrGrid) == 2)
	  {
	    cout << "Player 2 wins" << endl;
	    playerTwoWin++;
	    break;
	  }
	else if(move == 9) //9 moves has occured meaning board is filled and a tie has occurred
	  {
	    cout << "Tie" << endl;
	    break;
	  }
	
	//change player
	if(player == 1)
	  {
	    player = 2;
	  }
	else
	  {
	    player = 1;
	  }
      }

      cout << "\nTotal Wins\nPlayer 1: " << playerOneWin << "\nPlayer 2: " << playerTwoWin << "\n\n";
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

//returns 1 for player 1 wins, 2 for player 2 wins
int checkWin(int** array)
{
  //checks rows for wins by counting X's and O's in each row
  for(int r = 0; r < 3; r++)
    {
      int x = 0;
      int o = 0;
      for(int c = 0; c < 3; c++)
	{
	  switch(array[r][c])
	    {
	    case 1: //if X
	      x++;
	      break;
	    case 2: //if O
	      o++;
	      break;
	    }
		  
	  if(x == 3) //when there are 3 in a row it means there is a win
	    {
	      return 1;
	    }
	  else if(o == 3)
	    {
	      return 2;
	    }
	}
    }
  
  //checks columns for wins by counting X's and O's in each column
  for(int c = 0; c < 3; c++)
    {
      int x = 0;
      int o = 0;
      for(int r = 0; r < 3; r++)
	{
	  switch(array[r][c])
	    {
	    case 1: //if X
	      x++;
	      break;
	    case 2: //if O
	      o++;
	      break;
	    }
		  
	  if(x == 3) //when there are 3 in a column it means there is a win
	    {
	      return 1;
	    }
	  else if(o == 3)
	    {
	      return 2;
	    }
	}
    }

  //checks diagonals for player 1 wins then player 2 wins
  for(int p = 1; p < 3; p++)
    {
      if (array[0][0] == p && array[1][1] == p && array[2][2] == p)
	{
	  return p;
	}
      else if (array[2][0] == p && array[1][1] == p && array[0][2] == p)
	{ 
	  return p;
	}
    }
  return 0;
}
