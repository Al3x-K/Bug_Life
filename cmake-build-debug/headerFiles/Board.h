//
// Created by Asus on 17/04/2024.
//

#ifndef BUG_LIFE_C___BOARD_H
#define BUG_LIFE_C___BOARD_H

#include "Bug.h"
#include "../headerFiles/Crawler.h"
#include "../headerFiles/Hopper.h"

#include <vector>
#include <map>

class Board {

private:
    vector<Bug*> bugVector;
    map<pair<int,int>, vector<Bug*>> cells;

public:
    Board();
    ~Board();

    void initializeBugVector();
    void displayAllBugs();
    void displayAllCells();
    void updateCells();
    void findBug(int bugId);
    void displayLifeHistory();
    void safeLifeHistoryToFile();

    void tap();

};


#endif //BUG_LIFE_C___BOARD_H
