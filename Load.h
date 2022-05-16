#ifndef ASSIGN2_LOAD_H
#define ASSIGN2_LOAD_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "LinkedList.h"

using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;

class Load {
    public:
    Load(string fileName);
    void loadGame(string fileName);
    vector<string> splitStringToVec(string text, vector<string> bag);
    vector<string> getTileBag();
    vector<string> getPlayer1Hand();
    vector<string> getPlayer2Hand();
    vector<string> getTilePositions();
    string getPlayer1Name();
    string getPlayer2Name();
    int getPlayer1Score();
    int getPlayer2Score();
    string getCurrentPlayer();

    private:
    string fileName;

    string player1Name;
    int player1Score;
    vector<string> player1Hand;

    string player2Name;
    int player2Score;
    vector<string> player2Hand;

    vector<string> tileBag;

    vector<string> tilePositions;

    string currentTurn;


};

#endif