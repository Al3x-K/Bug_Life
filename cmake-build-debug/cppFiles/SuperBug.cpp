//
// Created by Asus on 29/04/2024.
//

#include "../headerFiles/SuperBug.h"
SuperBug::SuperBug(int id, int x, int y,Direction direction, int size, char type) : Bug(id, x, y, direction, size, type)
{
    shape.setRadius(20);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(55 + this->getPosition().first * 50, 55 + this->getPosition().second * 50);
}

void SuperBug::move()
{
    if(this->alive)
    {
        switch (direction)
        {
            case Direction::North:
                position.second--; //Move up
                break;
            case Direction::East:
                position.first--; //Move right
                break;
            case Direction::South:
                position.second++; //Move down
                break;
            case Direction::West:
                position.first++; //Move left
                break;

        }

        addToPath(position.first, position.second);
    }
}