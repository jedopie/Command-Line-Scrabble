
#include "Tile.h"

Tile::Tile(Letter letter, Value value) {
    this->letter = letter;
    this->value = value;
}

Tile::Tile(Tile& other):
    letter(other.letter),
    value(other.value)
    {  
    }

Tile::~Tile() {
}

Letter Tile::getLetter(){
    return this->letter;
}

Value Tile::getValue() {
    return this->value;
}

// Empty... for now?
