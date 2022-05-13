#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#define PLAYER1INDEX        0
#define PLAYER2INDEX        1

#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;
using std::ofstream;

#include "Player.h"
#include "Board.h"

class Game {
    public:
    Game();
    ~Game();
    void addPlayers(Player* player1, Player* player2);
    vector<Player*> getPlayers();
    LinkedList* getTileBag();
    void printLinkedList(ofstream& saveFile, LinkedList* list);
    void printVector(ofstream& saveFile,vector<string> boardTiles);
    void saveGame(string fileName);
    Board* getBoard();

    private:
    vector<Player*> players;
    LinkedList* tileBag;
    Board* board;
};

#endif