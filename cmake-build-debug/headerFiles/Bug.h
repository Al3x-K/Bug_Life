//
// Created by Asus on 10/04/2024.
//

#ifndef BUG_LIFE_C_BUG_H
#define BUG_LIFE_C_BUG_H

#include <iostream>
#include <list>
#include <utility>

using namespace std;

class Bug {
    int id;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:
    Bug(int id = 0, pair<int, int> position = {0,0}, int direction = 1, int size = 0, bool alive = true, list<pair<int, int>> path = {});
    int getId() const;
    pair<int, int> getPosition() const;
    int getDirection() const;
    int getSize() const;
    bool checkIfAlive() const;
    list<pair<int, int>> getPath() const;

    void setId(int bugId);
    void setPosition(pair<int, int> p);
    void setDirection(int d);
    void setSize(int s);
    void setStatus(bool alive);
    void addToPath();
};


#endif //BUG_LIFE_C_BUG_H
