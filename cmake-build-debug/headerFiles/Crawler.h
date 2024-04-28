
//
// Created by Asus on 10/04/2024.
//

#ifndef BUG_LIFE_C___CRAWLER_H
#define BUG_LIFE_C___CRAWLER_H


#include "Bug.h"

class Crawler : public Bug{

public:
    Crawler(int id, int x, int y, Direction direction, int size, char type);
    virtual ~Crawler(){}; //Destructor

    void move() override;
};


#endif //BUG_LIFE_C___CRAWLER_H
