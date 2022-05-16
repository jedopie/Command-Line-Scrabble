.default: all

all: scrabble

clean:
	rm -rf scrabble *.o *.dSYM

scrabble: Tile.o Node.o LinkedList.o Game.o Player.o Board.o Load.o scrabble.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
