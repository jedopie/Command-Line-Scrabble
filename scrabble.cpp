#include "Tile.h"
#include "LinkedList.h"
#include "Game.h"
#include "Node.h"
#include "Player.h"
#include "Load.h"

#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

#define NUM_PLAYERS     2

void showCredits();
void showMenu();
void startNewGame();
bool isUpper(string &input);
vector<string> splitStringToVec(string input, vector<string> vec);
void printWinner(vector<Player*> players, Player* winner);

#define EXIT_SUCCESS    0

int main(void) {
   // LinkedList* list = new LinkedList();
   // delete list;
   showMenu();

   std::cout << "TODO: Implement Scrabble!" << std::endl;

   return EXIT_SUCCESS;
}

void showCredits() {
   cout << "----------------------------------" << endl;
   cout << "Name: Jed Opie" << endl;
   cout << "Student ID: s3868658" << endl;
   cout << "Email: s3868658@student.rmit.edu.au" << endl;
   cout << endl;

   cout << "Name: Mohamed Nur" << endl;
   cout << "Student ID: s3841634" << endl;
   cout << "Email: s3841634@student.rmit.edu.au" << endl;
   cout << endl;

   cout << "Name: Mohammad Abu Taleb Rifat" << endl;
   cout << "Student ID: s3833673" << endl;
   cout << "Email: s3833673@student.rmit.edu.au" << endl;
   cout << endl;

   cout << "Name: Xiu Bin Guo" << endl;
   cout << "Student ID: s3841074" << endl;
   cout << "Email: s3841074@student.rmit.edu.au" << endl;
   cout << endl;
   cout << "----------------------------------" << endl;
   cout << endl;

   showMenu();
}

void showMenu() {
   cout << "Welcome to Scrabble!" << endl;
   cout << "-------------------" << endl;

   string input;
   bool quit = false;

   cout << "Menu" << endl;
   cout << "----" << endl;
   cout << "1. New Game" << endl;
   cout << "2. Load Game" << endl;
   cout << "3. Credits (Show student information)" << endl;
   cout << "4. Quit"<< endl;
   cout << endl;

   cout << "> ";
   cin >> input;

   while (input != "1" || input == "2" || input != "3" || input != "4") {
      if (cin.eof()) {
         quit = true;
      }
      else if (input == "1") {
         startNewGame();
      }
      else if (input == "2") {
         //load game
      }
      else if (input == "3") {
         showCredits();
      }
      else if (input == "4") {
         cout << "Goodbye" << endl;
         exit(EXIT_SUCCESS);
      }
      else {
         cout << "Invalid entry. Please try again" << endl;
      }
      cout << "> ";
      cin >> input;
   }
}

void startNewGame() {
   Game* game = new Game();
    // shuffled tileBag initalised
    LinkedList* tileBag = game->getTileBag();

    cout << "Starting a New Game \n" << endl;
    cout << "Enter a name for Player 1 (Uppercase characters only)" << endl;
    cout << "> ";
    string player1Name;
    cin >> player1Name; // grab player1 name from user input
    while (!isUpper(player1Name)) {
        cout << "Sorry, please enter a name with uppercase characters" << endl;

        cin >> player1Name;
    }

    cout << "\n" << endl;
    cout << "Enter a name for Player 2 (Uppercase characters only)" << endl;
    cout << "> ";
    string player2Name;
    cin >> player2Name;

    while (!isUpper(player2Name)) {
        cout << "Sorry, please enter a name with uppercase characters" << endl;

        cin >> player2Name;
    }
    cout << endl;

    cout << "Let's Play!" << endl;
    cout << endl;

    Player* player1 = new Player(player1Name); // create player objects
    Player* player2 = new Player(player2Name);

    game->addPlayers(player1,player2); // add to game.
    vector<Player*> players = game->getPlayers();



    player1->initalisePlayerHand(tileBag); // take 7 tiles from tileBag
    player2->initalisePlayerHand(tileBag);

    Board* board = game->getBoard(); // declare & initalise board


    // Player's input for their turn
    string input;
    char c;
    // int i = 0;
    while (tileBag->size() > 0) {
       cout << tileBag->size();
        for (int i = 0; i < NUM_PLAYERS; i++) {
            cout << players[i]->getName() << ", it's your turn" << endl; // prints name of current player
            cout << "Score for " << players[0]->getName() << ": " << players[0]->getScore() << endl; //name of player1
            cout << "Score for " << players[1]->getName() << ": " << players[1]->getScore() << endl; // name of player2
            board->printBoard(); // print the board
            cout << endl;
            cout << "Your hand is" << endl;
            players[i]->getPlayerHand()->printLinkedList(); //print player's hand
            do {
               cout << "> ";
               std::getline(cin >> std::ws, input);
               vector<string> inputs = {}; 
               inputs = splitStringToVec(input, inputs);
               c = inputs[1][0];

               if (input == "quit") { //if player inputs "quit", exit game safely
               cout << "Goodbye" << endl;
               exit(EXIT_SUCCESS);
               }
               // if player inputs "place" and following input is valid, place tile on board at given location
               if (inputs[0] == "place" && board->inputValid(inputs[3]) && !board->locationFilled(inputs[3])) {
                  if (players[i]->getPlayerHand()->isLetterinHand(c)) {
                     int j = players[i]->getPlayerHand()->searchForLetter(c);
                     Tile* tile = new Tile(*players[i]->getPlayerHand()->get(j));
                     board->insertTile(inputs[3], tile); // add to board
                     players[i]->getPlayerHand()->remove(j); // remove tile from hand
                     int addScore =0;
                     addScore += tile->value; //increment score by value of placed tile
                     players[i]->addToScore(addScore); // add to player's score
                     if (players[i]->getPlayerHand()->size() == 0) { //if player has zero tiles after turn, print bingo
                        cout << endl; 
                        cout << "BINGO!" << endl;
                        }
                     players[i]->resetPassTally();
                  }
                  else {
                     cout << inputs[1] << " is not in your hand. Try again" << endl;
                     // cout << board->locationFilled(inputs[3]);
                  }
               }
               else if (board->locationFilled(inputs[3]) == true) { //if location already filled
                     cout << "Sorry, a tile has already been placed there. Please try again." << endl;
                  }

               else if (input == "pass") {
                  players[i]->incrementPassTally();
                  if (players[i]->getPassTally() == 2) {
                     cout << "That was " << players[i]->getName() << "'s second pass in a row!" << endl;
                     cout << endl;
                     if (i ==0) {
                        printWinner(players, players[1]);
                     }
                     else {
                        printWinner(players, players[0]);
                     }
                  }
                  else {
                     input = "done";
                     cout << endl;
                  }
               }

               else if (inputs[0] == "replace") {
                  if (inputs[1] >= "A" && inputs[1] <= "Z") { // check if input is correct
                     if (players[i]->getPlayerHand()->isLetterinHand(inputs[1][0])) { // check if letter is in hand
                        int index = players[i]->getPlayerHand()->searchForLetter(inputs[1][0]);
                        Tile* tile = new Tile(*players[0]->getPlayerHand()->get(index)); //create reference to tile to be replaced
                        players[i]->getPlayerHand()->remove(index); // remove tile
                        players[i]->addTilesToHand(tileBag); //grab tile from tileBag
                        tileBag->addBack(tile); // add replaced tile to back of tileBag
                        players[i]->resetPassTally();
                        input = "done"; // end turn
                     }
                     else {
                        cout << "Sorry, " << inputs[1] << " is not in your hand. Try again." << endl;
                     }
                  }
                  else {
                     cout << "Invalid entry. Please Try again." << endl;
                  }
                  cout << endl;
               }

               else if (inputs[0] == "save") { 
                  game->saveGame(inputs[1]); // save game with fileName given by user
                  cout << endl;
                  cout << "Game successfully saved" << endl;
               }

               else if (input == "done") {
                  players[i]->addTilesToHand(tileBag); //add tiles to player's hand if size < 7
                  cout << endl;
               }
               else {
                  cout << "Invalid Entry. Try again." << endl;
               }
         } while (input != "done");
      }
      }
      if (players[0]->getScore() > players[1]->getScore()) { // if game runs out, player with highest score wins
         printWinner(players,players[0]);
      }
      else {
         printWinner(players,players[1]);
      }
}

bool isUpper(string &input) {
    return std::all_of(input.begin(), input.end(), [](unsigned char c){ return std::isupper(c); });

}

vector<string> splitStringToVec(string input, vector<string> vec){
    std::stringstream ss(input);
    while (ss.good()) {
        string substr;
        getline(ss,substr,' ');
        vec.push_back(substr);
    }
    return vec;
}

void printWinner(vector<Player*> players, Player* winner) {
   cout << "Game over" << endl;
   cout << "Score for " << players[0]->getName() << ": " << players[0]->getScore() << endl;
   cout << "Score for " << players[1]->getName() << ": " << players[1]->getScore() << endl;
   if (players[0] == winner) {
      cout << "Player " << players[0]->getName() << " won!" << endl;
   }
   else {
      cout << "Player " << players[1]->getName() << " won!" << endl;
   }
   cout << endl;
   cout << "Goodbye" << endl;
   exit(EXIT_SUCCESS);
}
