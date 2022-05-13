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

class Board {
    public:
    Board();

    vector<vector<Tile*>> getBoard();

    void printBoard();
    void insertTile(const string position, Tile* tile);
    bool isNumber(char c);
    bool inputValid(string position);



    private:
    // int tiles;

    vector<Tile*> gameRow;
    vector<vector<Tile*>> gBoard;


    
};

#endif