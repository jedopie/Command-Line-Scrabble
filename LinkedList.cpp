
#include "LinkedList.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <random>

#define     MAX      98

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}



LinkedList::~LinkedList() {
   // This method clears everything using the removeFront() method
   // multiple times
   clearLinkedList();
}


// Returns the number of nodes in the linkedlist
int LinkedList::size(){

   int length = 0;

   Node* current = head;
   while(current != nullptr){
      length++;
      current = current->next;

   }
   return length;
}

Tile* LinkedList::get(int index){
   Tile* returnTile = nullptr;

   // Defensive programming check
   //  if(index >= 0 && index < size()){

   int counter = 0;
   Node* currentNode = head;

   while(counter<index){
      ++counter;
      currentNode = currentNode->next;
   }

   returnTile = currentNode->tile;

//  }
   return returnTile;
}



void LinkedList::addBack(Tile* tile){
   Node* node = new Node(tile,nullptr);
   node->tile = tile;
   node->next = nullptr;


    if(head == nullptr){
        head = node;
    }else{
        Node* currentNode = head;
        while(currentNode->next != nullptr){
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    }
}

void LinkedList::removeFront(){

   if(head != nullptr){
      Node* nodeToDelete = head;
      head = head->next;

      delete nodeToDelete->tile;
      delete nodeToDelete;

   } else{ 
         // if the list is empty 
         throw std::runtime_error("The linkedlist is empty");  
      }

}

void LinkedList::removeBack(){

   if(head != nullptr){
      Node* currentNode = head;

      Node* previousNode = nullptr;

      while(currentNode->next != nullptr){
         previousNode = currentNode;
         currentNode = currentNode->next;
      }

      if(previousNode == nullptr){
         head = nullptr;
      }else{
         previousNode->next = nullptr;
      }

      delete currentNode->tile;
      delete currentNode;

   }

}

void LinkedList::remove(int index){
   // Check if the index is acceptable
   // 1.Has to be a positive number
   // 2.Cannot be greater than the size of the linked list (Out of bounds)
    if(index >= 0 && index < size()){
        if(head != nullptr){
            int counter = 0;
            // CurrentNode represents the node we want to remove & have to delete at the end
            Node* currentNode = head;
            //previousNode should point to node before currentNode;
            Node* previousNode = nullptr;

            while(counter != index){
                ++counter;
                previousNode = currentNode;
                currentNode = currentNode->next;
            }

            // If this is true - It means the node we removed was the first node in the linked-list
            if(previousNode == nullptr){
                head = currentNode->next;
            }else{
                previousNode->next = currentNode->next;
            }

            delete currentNode->tile;
            delete currentNode;
        }
    }

}
// check if input character is in the given LinkedList (for playerHand)
bool LinkedList::isLetterinHand(char character) {
   bool isIn = false;
   for (int i=0; i < size(); i++) {
      if (this->get(i)->getLetter() == character) {
         isIn= true;
      }
   }
   return isIn;
}

int LinkedList::searchForLetter(char character) {
   int count = 0;
   int index = -1;
   if (isLetterinHand(character)) {
      while(this->get(count)->getLetter() != character){
         count++;
      }
      index = count;
   }
   return index;
}

Tile* LinkedList::getTail() {
   Node* current = head;
   while(current->next != nullptr) {
      current = current->next;
   }
   return current->tile;
}

void LinkedList::clearLinkedList(){
     while(head != nullptr){
        removeFront();
    }
}

// Initalise original ordered tileBag(LinkedList) - Reads from file and populates list
void LinkedList::initaliseTileBag() {
   Letter letter;
   Value value;
   std::fstream myfile ("ScrabbleTiles.txt");
   int i =0;
   while (myfile && i< MAX ){
      myfile >> letter >> value;
      Tile* tile = new Tile(letter, value);
      this->addBack(tile);
      i++;
   }
}

// shuffles original, ordered tileBag and returns new shuffled LinkedList
LinkedList* LinkedList::shuffleTileBag() {
   LinkedList* shuffledList = new LinkedList();
   // vector to establish which tiles have already been visited
   std::vector<int> visited;
   int rand;
   Tile* tile = nullptr;

   // Bounds for random number
   int min = 0;
   int max = this->size();

   std::random_device engine;
   std::uniform_int_distribution<int> uniform_dist(min,max);

   // while not all tiles have been reached
   while (visited.size() != MAX) {
      rand = (uniform_dist(engine) % this->size()) + min;
      // if random index has already been checked -> choose a new index
      if (std::find(visited.begin(), visited.end(),rand)!=visited.end()){
         rand = (uniform_dist(engine) % this->size()) + min;
      }
      // 1. if random index has not yet been reached (check against Vector visited) -> add to vector
      // 2. create reference to tile and add to the returned list
      else {
         visited.push_back(rand);
         tile = new Tile(*this->get(rand));
         shuffledList->addBack(tile);
      }
   }
   return shuffledList;
}

void LinkedList::printLinkedList() {
    for (int i =0; i < size(); i++) {
        if (i < size() -1 ) {
            std::cout << this->get(i)->getLetter() << "-" << this->get(i)->getValue() << ",";
        }
        else {
            std::cout << this->get(i)->getLetter() << "-" << this->get(i)->getValue() << std::endl;
        }
    }
}
