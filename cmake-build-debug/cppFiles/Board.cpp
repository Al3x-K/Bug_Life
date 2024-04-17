//
// Created by Asus on 17/04/2024.
//

#include "../headerFiles/Board.h"

#include <iostream>
#include <fstream>
#include <sstream>

Board::Board() {}

Board::~Board()
{
    //Free memory allocated for bugs
    for(Bug* bug : bugVector)
    {
        delete bug;
    }
}

void Board::initializeBugVector()
{
    ifstream file("bugs.txt");
    if(!file.is_open())
    {
        //cerr is used in C++ to print out error messages
        cerr << "Error: Unable to open file bugs.txt" << endl;
        return;
    }

    string line;
    while(getline(file,line))
    {
        //istringstream is used to stream the string into different variables
        //it uses a string buffer that contains a sequence of characters
        //that can be accessed as a string object
        istringstream  iss(line);
        char type;
        int id, x, y, size, directionInt, hopLength;

        //attempt to extract values for each variable from the iss stream
        if(!(iss >> type >> id >> x >> y >> directionInt >> size))
        {
            cerr << "Error: Invalid line in bugs.txt" <<endl;
            continue;
        }

        Direction direction;
        switch(directionInt)
        {
            case 1:
                direction = Direction::North;
                break;
            case 2:
                direction = Direction::East;
                break;
            case 3:
                direction = Direction::South;
                break;
            case 4:
                direction = Direction::West;
                break;
            default:
                cerr << "Error: Invalid direction in bugs.txt" << endl;
                continue;
        }

        if(type == 'C')
        {
            bugVector.push_back(new Crawler(id, x, y, direction, size));
        }
        else if(type =='H')
        {
            if(!(iss >> hopLength))
            {
                //throws an error if the value for hopLength cannot be successfully streamed
                cerr << "Error: Invalid line in bugs.txt" << endl;
            }
            bugVector.push_back(new Hopper(id, x, y, direction, size, hopLength));
        }
        else
        {
            cerr << "Error: Invalid bug type in bugs.txt" << endl;
        }
    }
    file.close();
}

void Board::displayAllBugs()
{
    for(Bug* bug : bugVector)
    {
        cout << "Bug ID: " << bug->getId() << endl;
        cout << "Position: (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << endl;
        cout << "Direction: ";
        switch (bug->getDirection())
        {
            case Direction::North:
                cout << "North" << endl;
                break;
            case Direction::East:
                cout << "East" << endl;
                break;
            case Direction::South:
                cout << "South" << endl;
                break;
            case Direction::West:
                cout << "West" << endl;
                break;
        }
        cout << "Size: " << bug->getSize() << endl;
        cout << (bug->isAlive() ? "Status: Alive" : "Status: Dead") << endl;
        cout << endl;
    }
}

void Board::displayAllCells()
{
    //goes throught each cell in the cells map and checks if there is a bug (or more) or nah
    for(const auto& cell : cells)
    {
        cout << "Cell (" << cell.first.first << ", " << cell.first.second << "): ";
        if(cell.second.empty())
        {
            cout << "empty" << endl;
        }
        else
        {
            for(Bug* bug : cell.second)
            {
                cout << "Bug ID: " << bug->getId() << ", ";
            }
            cout << endl;
        }
    }
}