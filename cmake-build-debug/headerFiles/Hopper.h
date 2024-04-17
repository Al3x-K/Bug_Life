//
// Created by Asus on 17/04/2024.
//

#ifndef BUG_LIFE_C___HOPPER_H
#define BUG_LIFE_C___HOPPER_H

#include "Bug.h"

class Hopper : public Bug{

private:
    int hopLength;

public:
    Hopper(int id, int x, int y, Direction direction, int size, char type, int hopLength);
    virtual ~Hopper(){}; //Destructor

    void move() override;

};


#endif //BUG_LIFE_C___HOPPER_H
