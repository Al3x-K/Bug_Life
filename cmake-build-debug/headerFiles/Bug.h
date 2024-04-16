//
// Created by Asus on 10/04/2024.
//

#ifndef BUG_LIFE_C_BUG_H
#define BUG_LIFE_C_BUG_H

#include <iostream>
#include <list>
#include <utility>

using namespace std;

enum class Direction {North, East, South, West};

class Bug {
protected:
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:
    Bug(int id, int x, int y, Direction direction, int size);
    virtual ~Bug(); //Destructor

    int getId() const;
    pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    list<pair<int, int>> getPath() const;

    void setId(int bugId);
    void setPosition(pair<int, int> p);
    void setDirection(Direction d);
    void setSize(int s);
    void addToPath();

    void kill();
    void resurrect();
    virtual void move() = 0;
    bool isWayBlocked();
};


#endif //BUG_LIFE_C_BUG_H
