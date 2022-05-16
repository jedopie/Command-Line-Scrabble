#include "Player.h"
#include <iostream>

Player::Player(string name) {
    this->name = name;
    score = 0;
    playerHand = new LinkedList();
    currentTurn = false;
    passTally = 0;
}
string Player::getName() {
    return this->name;
}

int Player::getScore() {
    return this->score;
}

bool Player::isCurrentTurn() {
    return currentTurn;
}

void Player::setCurrentTurn() {
    currentTurn = true;
}

void Player::endCurrentTurn(){
    currentTurn = false;
}

void Player::setScore(int score) {
    // score cannot be a negative value
    if (score < 0) {
        this->score = 0;
    }
    else{
        this->score = score;
    }
}
// Adds to player's current score
void Player::addToScore(int addScore) {
    this->score += addScore;
}
// returns player's hand (Linked List)
LinkedList* Player::getPlayerHand() {
    return playerHand;
}
// Initialises player's hand at start of game (taking 7 tiles from tileBag)
void Player::initalisePlayerHand(LinkedList* tileBag) {
    Tile* tile;
    for (int i= 0; i < 7; i++) {
        tile = new Tile(*tileBag->get(i));
        playerHand->addBack(tile);
        tileBag->removeFront();
    }
}
// 1. Inputs character to be replaced and tileBag
// 2. check if input character is in player's hand
// 3. if true, get index of first occurrence of letter in hand
// 4. remove tile from player's hand 
// 5. take from tileBag (remove from list)
// 6. Add tile to back of player's hand.
void Player::replaceTile(char character, LinkedList* tileBag) {
    bool isIn = getPlayerHand()->isLetterinHand(character);
    int indexFound =0;
    Tile* tileToBag;
    Tile* tileToHand;
    if (isIn) {
        indexFound = getPlayerHand()->searchForLetter(character);
        tileToBag = new Tile (*getPlayerHand()->get(indexFound));
        tileToHand = new Tile(*tileBag->getTail());

        getPlayerHand()->remove(indexFound);
        getPlayerHand()->addBack(tileToHand);
        
        tileBag->removeBack();
        tileBag->addBack(tileToBag);
        std::cout << character << " Replaced!" << std::endl;
    }
    else {
        std::cout << character << " Character is not in hand" << std::endl;
    }
}

// after a player's turn -> add tiles to hand until player has 7 tiles
void Player::addTilesToHand(LinkedList* tileBag) {
    int length = getPlayerHand()->size();
    // Tile* tile;
    while (length <7) {
        Tile* bagTail = tileBag->getTail();
        Tile* tile = new Tile(*bagTail);
        getPlayerHand()->addBack(tile);
        tileBag->removeBack();
        length++;
    }
}

void Player::incrementPassTally() {
    passTally++;
}

void Player::resetPassTally() {
    this->passTally = 0;
}

int Player::getPassTally() {
    return this->passTally;
}