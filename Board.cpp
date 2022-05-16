#include "Board.h"

#include <iostream>

Board::Board() {
    gameRow.assign(MAX_BOARD_SIZE, nullptr);
    gBoard.assign(MAX_BOARD_SIZE, gameRow);
    placedTiles = {};
}

void Board::insertTile(const string position, Tile* tile) {
    int row = int(position[0] - ASCII_CHARACTERS);
    int column = int(position[1] - '0');

    // if third character is SPACE or NULL (if input row < 10)
    if ((position[2] == SYMBOL_SPACE || position[2] == SYMBOL_NULL) ) {
        column = int(position[1] -'0');
    }

    // else when input row > 10
    else {
        int char1 = int(position[1] - '0'); // get first index of col
        int char2 = int(position[2] - '0'); // get second number of col
        column = (char1*10) + char2; 
        /* first index * 10, then add second index, 
        eg. input = C12, position[1] == 1 & position[2] == 2 -> (1*10) + 2 = 12 */

    }
    // ensure input is within bounds 
    if (column < MAX_BOARD_SIZE && column >= 0 && inputValid(position)) {
        // if location is empty, place tile
        if (gBoard[row][column] == nullptr) {
            gBoard[row][column] = tile;
            // std::cout << tile->letter << " Added at " << position << std::endl;
            placedTiles.push_back(string(1,tile->letter) + "@" + position); // Add to placedTiles vector
        }
        else {
            std::cout << "Sorry, there is already a tile placed at " << position << ". Try Again." << std::endl;
        }
    }
    else {
        std::cout <<  "\"" <<position << "\" is an invalid location. Try Again." << std::endl;
    }
}

vector<vector<Tile*>> Board::getBoard() {
    return gBoard;
}

void Board::printBoard() {
    Letter letter;

    // printing column numbers
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        if (i < 10 ) {
            std::cout << "   " << i;
        }
        else {
            std::cout << "  " << i;
        }
    }
    std::cout << std::endl;
    std::cout << "  ";

    // printing border
    for (int i =0; i < MAX_BOARD_SIZE; i++){
        std::cout << "----";
    }
    std::cout << std::endl;

    // Printing row letters and board
    for (int i =0; i < gBoard.size(); i++) {
        std::cout << char(i + ASCII_CHARACTERS);
        // print tile if present
        for (int j =0; j < gBoard[i].size(); j++) {
            if (gBoard[i][j] == nullptr) {
                std::cout << "|   ";
            }
            else {
                letter = gBoard[i][j]->letter;
                std::cout << "| " << letter << " ";
            }
        }
        std::cout << "| " << std::endl;
    }
}

bool Board::isNumber(char c) {
    // std::cout << int(c);
    // if (int(c -'0') >= 1 && int(c-'0') <= 9) {
    //     return true;
    // }
    // return false;
    return (int(c -'0') >= 0 && int(c-'0') <= 9);
}

bool Board::isUpperCase(char c) {
    return int(c) >= 65 && int(c) <= 79;
}

bool Board::inputValid(string position) {
    if (!isNumber(position[1]) || (!isNumber(position[2]) && position[2] != SYMBOL_SPACE && position[2] != SYMBOL_NULL) || !isUpperCase(position[0])) {
        return false;
    }
    return true;
}

vector<string> Board::getPlacedTiles() {
    return placedTiles;
}

bool Board::locationFilled(string position) {
    for (int i =0; i < placedTiles.size(); i++) {
        if (placedTiles[i].substr(2,4) == position) {
            return true;
        }
    }
    return false;
}



