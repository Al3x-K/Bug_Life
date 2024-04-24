//
// Created by Asus on 24/04/2024.
//

#ifndef BUG_LIFE_C___DIZZLER_H
#define BUG_LIFE_C___DIZZLER_H
#include "Bug.h"

class Dizzler : public Bug {
private:
    bool dizzy = false;
public:
    Dizzler(int id, int x, int y, Direction direction, int size, char type);
    virtual ~Dizzler(){}; //Destructor

    void move() override;
};


#endif //BUG_LIFE_C___DIZZLER_H
