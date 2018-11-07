#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;

enum flag_types { NONE, ALIVE, DEAD};
class Game
{
	public:
		Game ();
		~Game ();
		void Init(int row, int Col);
		void Display(ostream & outs);
		void Check_neighbor_cells();
		void dead_or_alive();
		bool within_param(int row, int col);
	private:
		void Fill();
		void Check();
		struct GameSquare
		{
			GameSquare();
			void Display (ostream & outs);
			int status_value;
			flag_types status;
		};
		GameSquare ** grid;
		int numRows;
		int numCols;
		int game_board_size;
		
};

#endif
