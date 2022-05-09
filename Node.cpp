
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   this->tile = tile;
   this->next = next;
   // TODO
}

Node::Node(Node& other):
   tile(other.tile),
   next(other.next)
{  // TODO
}
