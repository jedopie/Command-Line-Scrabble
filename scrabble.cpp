
#include "LinkedList.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

void showMenu();

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "TODO: Implement Scrabble!" << std::endl;

   return EXIT_SUCCESS;
}

void showMenu() {
   cout << "Welcome to Scrabble!" << endl;
   cout << "-------------------" << endl;

   while (true) {
      cout << "Menu" << endl;
      cout << "----" << endl;
      cout << "1. New Game" << endl;
      cout << "2. Load Game" << endl;
      cout << "3. Credits" << endl;
      cout << "4. Quit" << endl;

      cout << ">";
      int userInput;
      cin >> userInput;
      cout << endl;
   }
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

}
