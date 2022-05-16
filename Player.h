#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include "LinkedList.h"

#include <string>

using std::string;

class Player {
public: 
Player(string name);
string getName(); 
int getScore();
bool isCurrentTurn();
void setCurrentTurn();
void endCurrentTurn();
void setScore(int score);
void addToScore(int addScore);
LinkedList* getPlayerHand();
void initalisePlayerHand(LinkedList* tileBag);
void replaceTile(char character, LinkedList* tileBag);
void addTilesToHand(LinkedList* tileBag);

void incrementPassTally();
void resetPassTally();
int getPassTally();

// Add bingo function -> if length of hand == 0 after turn, cout << Bingo






private:
int score;
string name;
LinkedList* playerHand;
bool currentTurn;
int passTally;

};
#endif