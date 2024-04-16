//
// Created by Asus on 10/04/2024.
//

#include "../headerFiles/Crawler.h"
#include <cstdlib> //For rand
#include <ctime>  //For srand

Crawler::Crawler(int id, int x, int y, Direction direction, int size)
: Bug(id,x,y,direction,size)
{
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
}

Crawler::~Crawler() {}

void Crawler::move()
{
    if (!isWayBlocked()) {
        switch (direction) {
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
    } else {
        direction = static_cast<Direction>(rand() % 4);
    }

    addToPath();
}