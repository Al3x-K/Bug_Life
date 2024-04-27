//
// Created by Asus on 10/04/2024.
//

#include <algorithm>
#include "../headerFiles/Bug.h"
#include "../headerFiles/Board.h"

Bug::Bug(int id, int x, int y, Direction direction, int size, char type)
: id(id),position(make_pair(x,y)),direction(direction), size(size), alive(true), type(type) {}

//GET METHODS
int Bug::getId() const
{
    return id;
}

pair<int, int> Bug::getPosition() const
{
    return position;
}

Direction Bug::getDirection() const
{
    return direction;
}

int Bug::getSize() const
{
    return size;
}

char Bug::getType() const
{
    return type;
}

list<pair<int, int>> Bug::getPath() const
{
    return path;
}

int Bug::getEatenBy() const
{
    return eaterId;
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

void Bug::setDirection(Direction d)
{
    this -> direction = d;
}

void Bug::setSize(int s)
{
    this -> size = s;
}

void Bug::addToPath(int x, int y)
{
    path.push_back(make_pair(x,y));
}

void Bug::setStatus(bool alive)
{
    this->alive = alive;
}

void Bug::setEatenBy(int eaterId)
{
    this->eaterId = eaterId;
}

//Different methods
bool Bug::isAlive() const
{
    return alive;
}

bool Bug::isWayBlocked()
{
    int boardWidth = 10;
    int boardHeight = 10;

    //Check if bug is at the left edge and facing West
    if(position.first == 0 && direction == Direction::West)
    {
        return true;
    }
    //Check if bug is at the right edge and facing East
    if(position.first == boardWidth - 1 && direction == Direction::East)
    {
        return true;
    }
    //Check if bug is at the top edge and facing North
    if(position.second == 0 && direction == Direction::North)
    {
        return true;
    }
    //Check if bug is at the bottom edge and facing South
    if(position.second == boardHeight - 1 && direction == Direction::South)
    {
        return true;
    }

    //Bug is not at any edge
    return false;
}


