//
// Created by Asus on 24/04/2024.
//

#include "../headerFiles/Dizzler.h"
#include <cstdlib> //For rand
#include <ctime>  //For srand

Dizzler::Dizzler(int id, int x, int y, Direction direction, int size, char type)
        : Bug(id,x,y,direction,size, type), dizzy(false)
{
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Dizzler::move()
{
    if(this->alive)
    {
        if (!dizzy)
        {
            direction = static_cast<Direction>(rand() % 4);

            if (hitWall() && isWayBlocked())
            {
                dizzy = true;
            }
            else
            {
                switch (direction) {
                    case Direction::North:
                        position.second--;
                        break;
                    case Direction::East:
                        position.first++;
                        break;
                    case Direction::South:
                        position.second++;
                        break;
                    case Direction::West:
                        position.first--;
                        break;
                }
            }
        }
        else
        {
            dizzy = false;
        }

        addToPath(position.first, position.second);
    }
}

bool Dizzler::hitWall() const
{
   return position.first == 0 || position.first == 9 || position.second == 0 || position.second == 9;
}