//
// Created by Asus on 17/04/2024.
//

#include "../headerFiles/Board.h"

#include <iostream>
#include <fstream>
#include <sstream>

Board::Board()
{

}

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
            bugVector.push_back(new Crawler(id, x, y, direction, size, type));
            //cells[make_pair(x,y)].push_back(new Crawler(id, x, y, direction, size, type));
        }
        else if(type =='H')
        {
            if(!(iss >> hopLength))
            {
                //throws an error if the value for hopLength cannot be successfully streamed
                cerr << "Error: Invalid line in bugs.txt" << endl;
            }
            bugVector.push_back(new Hopper(id, x, y, direction, size, type, hopLength));
            //cells[make_pair(x,y)].push_back(new Hopper(id, x, y, direction, size, type, hopLength));
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
        cout <<  bug->getId();
        if(bug->getType() == 'C')
        {
            cout << " Crawler ";
        }
        else if(bug->getType() =='H')
        {
            cout << " Hopper ";
        }
        cout << "(" << bug->getPosition().first << "," << bug->getPosition().second << ") ";
        cout << bug->getSize();
        switch (bug->getDirection())
        {
            case Direction::North:
                cout << " North ";
                break;
            case Direction::East:
                cout << " East ";
                break;
            case Direction::South:
                cout << " South ";
                break;
            case Direction::West:
                cout << " West ";
                break;
        }

        cout << (bug->isAlive() ? "Alive" : "Dead");
        cout << endl;
    }
}

void Board::findBug(int bugId)
{
    bool bugFound = false;

    //Go through each bug in the vector
    for(Bug* bug : bugVector)
    {
        if(bug->getId() == bugId)
        {
            //bug with specified id is found
            bugFound = true;
            cout <<  bug->getId() << " ";
            cout << (dynamic_cast<Crawler*>(bug) ? "Crawler" : "Hopper") << " ";
            cout << "(" << bug->getPosition().first << "," << bug->getPosition().second << ") ";
            cout << bug->getSize();
            switch (bug->getDirection())
            {
                case Direction::North:
                    cout << " North ";
                    break;
                case Direction::East:
                    cout << " East ";
                    break;
                case Direction::South:
                    cout << " South ";
                    break;
                case Direction::West:
                    cout << " West ";
                    break;
            }

            cout << (bug->isAlive() ? "Alive" : "Dead");
            cout << endl;
        }
        break;
    }
    if(!bugFound)
    {
        cout << "Bug " << bugId << " not found." << endl;
    }
}

void Board::displayAllCells()
{
    for (int y = 0; y < 10; ++y) //rows
    {
        for (int x = 0; x < 10; ++x) //columns
        {
            pair<int, int> cellCoordinates = make_pair(x, y); //coordinates of the current cell
            cout << "(" << x << "," << y << "): ";

            //attempt to locate the current cells coordinates in the map
            //if the cell is found, it will point to the corresponding entry
            auto it = cells.find(cellCoordinates);
            //no cell in the map or no bugs in the cell
            if (it == cells.end() || it->second.empty())
            {
                cout << "empty" << std::endl;
            }
            else
            {
                bool firstBug = true; //used just for formatting
                for (Bug *bug: it->second)
                {
                    if (!firstBug)
                    {
                        cout << ", ";
                    }
                    cout << (dynamic_cast<Crawler *>(bug) ? "Crawler" : "Hopper") << " " << bug->getId();
                    //dynamic cast is used for the type conversion of polymorphic types
                    //aka the types with at least one virtual function
                    //checks if a pointer or reference of base class can be safely
                    //converted to a pointer or reference to a derived class
                    firstBug = false;
                }
                cout << std::endl;
            }
        }
    }
}

void Board::tap()
{
    for(Bug* bug : bugVector)
    {
        bug->move();
    }
}