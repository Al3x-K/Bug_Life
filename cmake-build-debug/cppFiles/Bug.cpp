//
// Created by Asus on 10/04/2024.
//

#include "../headerFiles/Bug.h"

//GET METHODS
int Bug::getId() const
{
    return id;
}

pair<int, int> Bug::getPosition() const
{
    return position;
}

int Bug::getDirection() const
{
    return direction;
}

int Bug::getSize() const
{
    return size;
}

bool Bug::checkIfAlive() const
{
    return alive;
}

list<pair<int, int>> Bug::getPath() const
{
    return path;
}


//SET METHODS
void Bug::setId(int bugId)
{
    this -> id = bugId;
}

void Bug::setPosition(pair<int, int> p)
{
    this -> position = p;
}

void Bug::setDirection(int d)
{
    this -> direction = d;
}

void Bug::setSize(int s)
{
    this -> size = s;
}

void Bug::setStatus(bool status)
{
    this-> alive = status;
}

void Bug::addToPath()
{
    path.push_back(this->getPosition());
}