#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

#include "Tile.h"

using std::vector;
using std::string;
using std::ostream;

#define MAX_BOARD_SIZE          15
#define ASCII_CHARACTERS        65
#define SYMBOL_SPACE            32
#define SYMBOL_NULL             0

class Board {
    public:
    Board();

    vector<vector<Tile*>> getBoard();

    void printBoard();
    void insertTile(const string position, Tile* tile);
    bool isNumber(char c);
    bool isUpperCase(char c);
    bool inputValid(string position);
    bool locationFilled(string position);
    vector<string> getPlacedTiles();



    private:
    // int tiles;

    vector<Tile*> gameRow;
    vector<vector<Tile*>> gBoard;
    vector<string> placedTiles;


    
};

#endif