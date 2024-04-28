//
// Created by Asus on 28/04/2024.
//

#ifndef BUG_LIFE_C___GUI_H
#define BUG_LIFE_C___GUI_H


#include <SFML/Graphics.hpp>
#include "Board.h"

class GUI {
private:
    sf::RenderWindow window;
    Board& board;
    vector<sf::RectangleShape> background;
    bool over;
    int alive;
    int round;

public:
    GUI(Board& board);
    void run();
    void drawBug(char &type, pair<int, int> &position);
    void drawGUI();
    void makeBackground();
    void events();
    void runSimulation();
};


#endif //BUG_LIFE_C___GUI_H
