game_of_life.out: life_game.o h_file.o
		  g++ -g -o game_of_life.out life_game.o h_file.o

life_game.o: life_game.cpp game_of_life.h
	    g++ -g -c life_game.cpp

h_file.o: h_file.cpp game_of_life.h
	g++ -g -c h_file.cpp

run : game_of_life.out
	game_of_life.out

