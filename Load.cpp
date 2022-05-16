#include "Load.h"

// Load game, then store variable into Player objects
// eg. player->setScore(load->getPlayer1Score())

Load::Load(string fileName) {
    this->fileName = fileName;

    player1Name = "";
    player1Score = 0;
    player1Hand = {};

    player2Name = "";
    player1Score = 0;
    player2Hand = {};

    tileBag = {};
}
// Loads lines into their respective containers
// Player hand and tileBag first stored as vectors, to where they can be made into tile objects.
void Load::loadGame(string fileName) {
    string text;
    ifstream file;

    file.open(fileName);

    if(file.is_open()) {
        getline(file,text);
        player1Name = text;
        getline(file,text);
        player1Score = std::stoi(text);
        getline(file, text);
        player1Hand = splitStringToVec(text, player1Hand); 

        getline(file,text);
        player2Name = text;
        getline(file, text);
        player2Score = std::stoi(text);
        getline(file,text);
        player2Hand = splitStringToVec(text,player2Hand);

        getline(file,text);
        tilePositions = splitStringToVec(text,tileBag);
        getline(file,text);
        tileBag = splitStringToVec(text,tileBag);

        getline(file,text);
        currentTurn = text;
    }
}

//Splits TileBag/Player Hand strings to <letter>-<value> and adds to string vector
vector<string> Load::splitStringToVec(string text, vector<string> bag) {
    std::stringstream ss(text);
    while (ss.good()) {
        string substr;
        getline(ss,substr,',');
        bag.push_back(substr);
    }
    return bag;
}

vector<string> Load::getTileBag() {
    return tileBag;
}

string Load::getPlayer1Name() {
    return player1Name;
}

int Load::getPlayer1Score() {
    return player1Score;
}

vector<string> Load::getPlayer1Hand() {
    return player1Hand;
}

string Load::getPlayer2Name() {
    return player2Name;
}

int Load::getPlayer2Score() {
    return player2Score;
}

vector<string> Load::getPlayer2Hand() {
    return player2Hand;
}

vector<string> Load::getTilePositions() {
    return tilePositions;
}

string Load::getCurrentPlayer() {
    return currentTurn;
}