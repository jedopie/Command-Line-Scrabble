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
void setScore(int score);
void addToScore(int addScore);
LinkedList* getPlayerHand();
void initalisePlayerHand(LinkedList* tileBag);
void replaceTile(char character, LinkedList* tileBag);





private:
int score;
string name;
LinkedList* playerHand;

};
#endif