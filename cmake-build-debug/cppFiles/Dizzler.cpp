//
// Created by Asus on 24/04/2024.
//

#include "../headerFiles/Dizzler.h"
#include <cstdlib> //For rand
#include <ctime>  //For srand

Dizzler::Dizzler(int id, int x, int y, Direction direction, int size, char type, bool dizzy)
        : Bug(id,x,y,direction,size, type), dizzy(dizzy)
{
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Dizzler::move()
{
    while(isWayBlocked())
    {
        direction = static_cast<Direction>(rand() % 4);
    }
    switch (direction)
    {
        case Direction::North:
            position.second--; //Move up
            break;
        case Direction::East:
            position.first++; //Move right
            break;
        case Direction::South:
            position.second++; //Move down
            break;
        case Direction::West:
            position.first--; //Move left
            break;

    }
    addToPath(position.first, position.second);
}