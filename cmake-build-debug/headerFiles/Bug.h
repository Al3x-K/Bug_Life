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
    char type;
    int eatenBy = -1;

public:
    Bug(int id, int x, int y, Direction direction, int size, char type);
    virtual ~Bug(){}; //Destructor

    int getId() const;
    pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    char getType() const;
    list<pair<int, int>> getPath() const;
    int getEatenBy() const;

    void setId(int bugId);
    void setPosition(pair<int, int> p);
    void setDirection(Direction d);
    void setSize(int s);
    void addToPath(int x, int y);
    void setEatenBy(int id);

    void kill();
    void resurrect();
    virtual void move() = 0;
    bool isWayBlocked();
};


#endif //BUG_LIFE_C_BUG_H
