//
// Created by Asus on 29/04/2024.
//

#ifndef BUG_LIFE_C___SUPERBUG_H
#define BUG_LIFE_C___SUPERBUG_H


#include <SFML/Graphics.hpp>
#include "Bug.h"

class SuperBug : public Bug{
public:
    SuperBug(int id, int x, int y, Direction direction, int size, char type);
    sf::CircleShape shape;
    virtual ~SuperBug(){}; //Destructor

    void move() override;
};


#endif //BUG_LIFE_C___SUPERBUG_H
