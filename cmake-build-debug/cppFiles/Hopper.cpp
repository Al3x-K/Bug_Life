//
// Created by Asus on 17/04/2024.
//

#include "../headerFiles/Hopper.h"
#include <cstdlib> //For rand
#include <ctime> //For srand

Hopper::Hopper(int id, int x, int y, Direction direction, int size, char type, int hopLength)
: Bug(id, x, y, direction, size, type), hopLength(hopLength)
{
    srand(time(nullptr));
}

//Hopper::~Hopper() {}

void Hopper::move()
{
    //Calculate new position based on current direction and hop length
    int nextX = position.first;
    int nextY = position.second;
    if(this->alive)
    {
        while(isWayBlocked())
        {
            direction = static_cast<Direction>(rand() % 4);
        }

        switch(direction)
        {
            case Direction::North:
                nextY -= hopLength;
                break;
            case Direction::East:
                nextX += hopLength;
                break;
            case Direction::South:
                nextY += hopLength;
                break;

            case Direction::West:
                nextX -= hopLength;
                break;
        }
        //Check if the next position is within boundaries of the board
        if(nextX >= 0 && nextX < 10 && nextY >= 0 && nextY < 10)
        {
            position = make_pair(nextX,nextY); //update position
        }
        else
        {
            if(nextX < 0)
                nextX=0;
            else if(nextX>9)
                nextX = 9;
            if(nextY  < 0)
                nextY=0;
            else if(nextY>9)
                nextY = 9;

            position = make_pair(nextX,nextY); //update position
        }

        addToPath(nextX,nextY);
    }
}
