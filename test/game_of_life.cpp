#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;


int number_generator()
{
	int number = rand()%2;
	cout << " ---- number " << number <<endl;
	return number;
}	

int populate_game_board(int row, int col, int game_board[row][col], int game_board_size)
{
	
	for (int i = 0; i < game_board_size -1 ; i ++)
	{
		for (int j =0; j < game_board_size - 1; j++)
		{
	
			int random_number = number_generator();
			game_board[i][j] = random_number;
		}
	}
}
	
/**int print_game_board(int game_board_row,int  game_board_col,int row_size,int col_size)
{
	for(int i = 
	
}**/	

int main()
{
	
	srand(time(NULL));
	int game_board_size = 10;	
	int game_board[game_board_size][game_board_size];
	int CELL_DEAD = 0;
	int CELL_ALIVE = 1;
	populate_game_board(game_board_size,game_board_size,game_board[game_board_size][game_board_size], game_board_size);

	for (int i = 0; i < game_board_size - 1; i ++)
	{
		for (int j =0; j < game_board_size - 1; j++)
		{
	
			cout << game_board[i][j];
		}
		cout << endl;

	}	
	return 0;
}
