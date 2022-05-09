
#include "LinkedList.h"
#include <stdexcept>

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

Tile* get(int index){
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

void LinkedList::clearLinkedList(){
     while(head != nullptr){
        removeFront();
    }
}
