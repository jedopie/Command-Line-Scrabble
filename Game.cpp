#include "Game.h"

Game::Game() {
    LinkedList* orderedTileBag = new LinkedList();
    orderedTileBag->initaliseTileBag();
    tileBag = orderedTileBag->shuffleTileBag();
    board = new Board();
}

Game::~Game() {

}

void Game::addPlayers(Player* player1, Player* player2) {
    players.push_back(player1);
    players.push_back(player2);
}

vector<Player*> Game::getPlayers() {
    return players;
}

LinkedList* Game::getTileBag() {
    return tileBag;
}

// Save game to .save file (Still need board)
void Game::saveGame(string fileName) {
    Player* player1 = players[PLAYER1INDEX];
    Player* player2 = players[PLAYER2INDEX];

    string player1Name = player1->getName();
    int player1Score = player1->getScore();
    LinkedList* player1Hand = player1->getPlayerHand();

    string player2Name = player2->getName();
    int player2Score = player2->getScore();
    LinkedList* player2Hand = player2->getPlayerHand();
    
    vector<string> placedTiles = board->getPlacedTiles();
    // then board
    // tileBag already defined
    string currentPlayer;
    if (player1->isCurrentTurn() == true) {
        currentPlayer = player1->getName();
    }
    else {
        currentPlayer = player2->getName();
    }

    ofstream saveFile;
    saveFile.open(fileName + ".save");
    saveFile << player1Name << "\n";
    saveFile << player1Score << "\n";
    printLinkedList(saveFile, player1Hand);

    saveFile << "\n";

    saveFile << player2Name << "\n";
    saveFile << player2Score << "\n";
    printLinkedList(saveFile, player2Hand);

    saveFile << "\n";

    // print board
    printVector(saveFile, placedTiles);
    saveFile << "\n";

    printLinkedList(saveFile, tileBag);
    saveFile << "\n" << currentPlayer;
}

// formatting input list for saveGame file or printing hand for player.
void Game::printLinkedList(ofstream& saveFile, LinkedList* list) {
    for (int i =0; i < list->size(); i++) {
        if (i < list->size() -1 ) {
            saveFile << list->get(i)->getLetter() << "-" << list->get(i)->getValue() << ",";
        }
        else {
            saveFile << list->get(i)->getLetter() << "-" << list->get(i)->getValue();
        }
    }
}

Board* Game::getBoard() {
    return board;
}

void Game::printVector(ofstream& saveFile, vector<string> boardTiles) {
    for (int i =0; i < boardTiles.size(); i++) {
        if (i < boardTiles.size() -1) {
            saveFile << boardTiles[i] << ",";
        }
        else {
            saveFile << boardTiles[i];
        }
    }
}
