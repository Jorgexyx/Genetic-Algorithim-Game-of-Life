#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "game_of_life.h"

Game::GameSquare::GameSquare ()
{
	// This function sets the default constructors
	status_value = 1;
	status = NONE;
	
}

void Game::GameSquare::Display (ostream & outs)
{	
	// This creates an array that contains the images for the cells. If the cell is dead, aka its status value is 0, outs will print out a blank space, if it is alive,aka one, it will print out a black bar.
	//cout << "-------game square display --"  ;	
	string images[2] = {" ", "█"};
	outs << images[status_value];
}

Game::Game ()
{
	//cout << "-------**** GAME CONSTRUCOT*******----------" << endl;
	numRows = 1;
	//cout << "----* numrows created --*" << endl;
	numCols = 1;
	cout << "4232" << endl;
	game_board_size = 1;
	grid = new GameSquare * [3];
	for (int r = 0; r < 3; r++)
	{//	cout << "saasgasga" << endl;
		grid[0] = new GameSquare[3];
	}
}

Game::~Game ()
{
	//cout << "--------****** DESTRUCTOR 8888888---------" << endl;
	for (int r =0; r< numRows; r++)
	{
	////	cout << " ---for loop for destructo --" << endl;
		delete [] grid[r];
	}
	delete [] grid;
}

void Game::Init(int row, int col)
{
//	cout << "~*----------INITILIZATION STARTED ------*~" << endl;
	//* This section of the code makes memory for the grid space by removing the default variables set in the default constructor note numrows equals one here still **//

	if( numRows == 1)
	{	
		for (int r = 0; r < numRows + 2; r ++)
		{//	cout << "!____------- for loop to delete grid[r] started ------___!" << endl;
		//	cout << numRows << r << endl;
			delete [] grid[r];
		}
		delete [] grid;

	// deletion ends
	}
	else
	{	
		for (int r = 0; r < numRows; r ++)
		{//	cout << "!____------- for loop to delete grid[r] started ------___!" << endl;
		//	cout << numRows << r << endl;
			delete [] grid[r];
		}
		delete [] grid;

	// deletion ends
	}
		
	numRows = row;
	numCols = col;
	grid = new GameSquare * [numRows]; // creates a grid with the number of rows
	//cout << "griid has been created" << endl;
	for (int r = 0; r< numRows ; r++)
	{
		grid[r] = new GameSquare [numCols]; // creates a col for each row
		//cout << "grid cols being added to grid row \n" ;
	}
	Fill();
	dead_or_alive();
	Check_neighbor_cells();
}

void Game::Fill()
{	
	// This will fill the first generation of the gameboard
 	//cout << "fill function called \n";	
	for ( int row = 0; row < numRows ; row++)
	{
		for(int col = 0; col < numCols ; col++)
		{
	//		cout << "alive or dead status being generated here for this specific row and col( i and j) " << row << " " << col << endl;
			grid[row][col].status_value = rand()%2;
		}
		
	}
}

bool Game::within_param(int row, int col)
{
	if ( row - 1 >= 0 && col - 1 >= 0 || row + 1 < numRows && col + 1 < numCols)
		{	return true;}
	else
		return false;
}
void Game::Check_neighbor_cells()
{
	for(int i = 0; i <= numRows; i ++)
	{
		for (int j = 0 ; j <= numCols; j ++)
		{
			if ( within_param(i,j) == true)
			{
				//if( grid[i][j].status == ALIVE & 
				//cout << "true worked \n";
			}
			if ( within_param(i,j) == false)
				cout << "false " << i << j << endl;
		}
	}
	
}

void Game::dead_or_alive()
{
	for(int i = 0 ; i < numRows ; i ++)
	{
		
		for(int j = 0; j < numCols ; j++)
		{
			
			if(grid[i][j].status_value == 0)
			{
				grid[i][j].status = DEAD;
			}
			else
			{	
				grid[i][j].status = ALIVE;
			}
		}
	}
}

void Game::Display(ostream & outs)
{
	// this function will display the brackets for the gameboard []
	system("clear");
	cout << "Display has started " << endl;
	for(int row = 0; row < numRows; row++)
	{
		for( int col = 0; col < numCols; col++)
		{
			
		outs << "[ ";
			grid[row][col].Display(outs);
	
		outs << " ]";
		}
		outs << endl << endl;
	}
}

