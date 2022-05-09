#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();
   Tile* get(int index);
   void addBack(Tile* data);
   void removeFront();
   void removeBack();
   void remove(int index);
   void clearLinkedList();
   void initaliseTileBag();



private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H

