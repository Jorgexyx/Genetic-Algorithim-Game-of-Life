#include <iostream>
#include "game_of_life.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while(goal > clock());
}
int main()
{
	srand(time(NULL));
	int row,col;
	
	cout << "Enter Number of rows: " << endl;
	cin >> row;
	cout << "Enter Number of Cols: " << endl;
	cin >> col;

	Game game_of_life;
	for(int i = 0; i < 100; i++)
	{
	cout << endl << endl;
	game_of_life.Init(row,col);
	game_of_life.Display(cout);
	
	cout << "this is the " << i << "th generation  \n"; 	
	sleep(180000);
	}
}

