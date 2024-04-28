//
// Created by Asus on 28/04/2024.
//


#include <thread>
#include "../headerFiles/GUI.h"

using namespace sf;

GUI::GUI(Board& board) : board(board)
{
    over = false;
    window.create(VideoMode(600,600),"Bug's Life");
    makeBackground();
}

void GUI::run()
{
    while(window.isOpen())
    {
        events();
        runSimulation();
        drawGUI();
    }
}

void GUI::events()
{
    Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void GUI::drawBug(char &type, pair<int, int> &position)
{

        CircleShape bugShape(20);
        if(type == 'C')
        {
            bugShape.setFillColor(Color::Red);
        }
        else if(type == 'H')
        {
            bugShape.setFillColor(Color::Green);
        }
        else if(type == 'D')
        {
            bugShape.setFillColor(Color::Blue);
        }
        bugShape.setPosition(55 + position.first * 50, 55 + position.second * 50);
        bugShape.setOutlineColor(Color::Black);
        bugShape.setOutlineThickness(1);
        window.draw(bugShape);

}

void GUI::makeBackground()
{
    for(int y = 0; y < 10; y++)
    {
        for(int x = 0; x < 10; x++)
        {
            RectangleShape cell(Vector2f(50,50));
            cell.setFillColor(Color::White);
            cell.setPosition(50 + x * 50,50 + y * 50);
            cell.setOutlineColor(Color::Black);
            cell.setOutlineThickness(1);
            background.push_back(cell);
        }
    }
}

void GUI::drawGUI()
{
    window.clear();
    for(auto &cell : background)
    {
        window.draw(cell);
    }
    auto bugs = board.getPosOfAlive();
    for(auto &bug : bugs)
    {
        drawBug(bug.first, bug.second);
    }
    window.display();
}

void GUI::runSimulation()
{
    auto sTime = chrono::steady_clock::now();
    while(!over)
    {
        auto currentTime = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(currentTime-sTime).count();

        if(1000 < elapsed)
        {
            sTime = chrono::steady_clock::now();
            board.tap();
            alive = board.aliveBugs();
            round++;

            if(round > 100)
            {
                over = true;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(1000));
    }


}