#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();
   Tile* get(int index);
   Tile* getTail();
   void addBack(Tile* data);
   void removeFront();
   void removeBack();
   void remove(int index);
   void clearLinkedList();
   void initaliseTileBag();
   int searchForLetter(char character);
   bool isLetterinHand(char character);
   LinkedList* shuffleTileBag();
   void printLinkedList();




private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H

