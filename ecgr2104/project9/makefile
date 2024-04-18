survival_game: main.o
	g++ main.o -o survival_game

main.o : main.cpp player.hpp land.hpp
	g++ -c main.cpp -std=c++11 -o main.o

clean:
	rm ./*.o ./survival_game