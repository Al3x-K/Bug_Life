//
// Created by Asus on 17/04/2024.
//

#include "../headerFiles/Board.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>

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
            Bug *crawler = new Crawler(id, x, y, direction, size, type);
            bugVector.push_back(crawler);
            crawler->addToPath(x,y);
        }
        else if(type == 'D')
        {
            Bug *dizzler = new Dizzler(id,x,y,direction,size,type);
            bugVector.push_back(dizzler);
            dizzler->addToPath(x,y);
        }
        else if(type =='H')
        {
            if(!(iss >> hopLength))
            {
                //throws an error if the value for hopLength cannot be successfully streamed
                cerr << "Error: Invalid line in bugs.txt" << endl;
            }
            Bug *hopper = new Hopper(id, x, y, direction, size, type, hopLength);
            bugVector.push_back(hopper);
            hopper->addToPath(x,y);
        }
        else
        {
            cerr << "Error: Invalid bug type in bugs.txt" << endl;
        }
    }
    file.close();
    updateCells();
}

void Board::displayAllBugs()
{
    cout << endl;
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
        else if(bug->getType() =='D')
        {
            cout << " Dizzler ";
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
            if(bug->getType() == 'D')
            {
                cout <<"Dizzler ";
            }
            else
            {
                cout << (dynamic_cast<Crawler*>(bug) ? "Crawler" : "Hopper") << " ";
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
    if(!bugFound)
    {
        cout << "Bug " << bugId << " not found." << endl;
    }
}

void Board::displayAllCells()
{
    cout << endl;
    for (int y = 0; y < 10; ++y) //rows
    {
        for (int x = 0; x < 10; ++x) //columns
        {
            pair<int, int> cellCoordinates = make_pair(x, y); //coordinates of the current cell
            cout << "(" << x << "," << y << "): ";

            //if the cell is found, it will point to the corresponding entry
            auto it = cells.find(cellCoordinates);
            //no cell in the map or no bugs in the cell
            if (it == cells.end() || it->second.empty())
            {
                cout << "empty" << endl;
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
                    if(bug->getType() == 'D')
                    {
                        cout <<"Dizzler " << bug->getId();
                    }
                    else
                    {
                        cout << (dynamic_cast<Crawler *>(bug) ? "Crawler" : "Hopper") << " " << bug->getId();
                    }
                    //dynamic cast is used for the type conversion of polymorphic types
                    //aka the types with at least one virtual function
                    //checks if a pointer or reference of base class can be safely
                    //converted to a pointer or reference to a derived class
                    firstBug = false;
                }
                cout << endl;
            }

        }
    }
}
void Board::updateCells()
{
    cells.clear(); //clear the map before updating

    for(Bug* bug : bugVector)
    {
        //get the position of the bug
        pair<int,int> position = bug->getPosition();
        //calculate the cell coordinates based on the bug's position
        //max(0, min(position.*,9)) ensures that the position is within the bounds of the board
        int cellX = max(0, min(position.first,9));
        int cellY = max(0, min(position.second,9));

        //insert the bug into corresponding cell in the cells map
        cells[{cellX,cellY}].push_back(bug);
    }
}

void Board::tap()
{

    for(Bug* bug : bugVector)
    {
        bug->move();
        fight();
    }

    //deleteDeadBugs();

    updateCells();
}
void Board::eat(Bug *bug1, Bug *bug2)
{

    if(bug1->getSize() > bug2->getSize())
    {
        //Bug1 is the winner
        bug1->setSize(bug1->getSize() + bug2->getSize());
        bug2->setStatus(false);
        bug2->setEatenBy(bug1->getId());
    }
    else if(bug2->getSize() < bug1->getSize())
    {
        //Bug2 is the winner
        bug2->setSize(bug2->getSize() + bug1->getSize());
        bug1->setStatus(false);
        bug1->setEatenBy(bug2->getId());
    }
    else
    {
        //If bugs have same size
        int winIndex = rand() % 2; //get random num (0 or 1)
        Bug* winner = winIndex == 0 ? bug1 : bug2; // Select a random bug as the winner
        Bug* loser = winIndex == 0 ? bug2 : bug1; // Select the other bug as the loser

        loser->setEatenBy(winner->getId());
        loser->setStatus(false);
    }
}

void Board::fight()
{
    for(const auto& cell : cells)
    {
        const auto& bugsInCell = cell.second;
        if(bugsInCell.size() > 1)
        {
            Bug* bug1 = bugsInCell.front();
            Bug* bug2 = bugsInCell.back();
            if(bug1 != bug2)
            {
                eat(bug1,bug2);
            }
        }
    }
}

void Board::displayLifeHistory(ostream& out)
{
    cout << endl;
    for (Bug *bug: bugVector)
    {
        if(dynamic_cast<Dizzler*>(bug))
        {
            out << bug->getId() << " Dizzler" << " Path: ";
        }
        else
        {
            out << bug->getId() << " " << (dynamic_cast<Crawler *>(bug) ? "Crawler" : "Hopper") << " Path: ";
        }
        const list<pair<int, int>> &path = bug->getPath();
        if (!path.empty()) {
            //print each position in the bug's path
            for (auto it = path.begin(); it != path.end(); it++) {
                out << "(" << it->first << "," << it->second << ")" << "";
                if (next(it) != path.end()) {
                    out << ",";
                }
            }
        } else {
            out << "No path recorded";
        }
        if (!bug->isAlive())
        {
            out << " Eaten by " << bug->getEatenBy();
        }
        else
        {
            out << " Alive!";
        }
        out << endl;
    }
}

void Board::deleteDeadBugs()
{
    auto it = bugVector.begin();
    while(it != bugVector.end())
    {
        if(!(*it)->isAlive())
        {
            delete *it; //Free memory
            it = bugVector.erase(it); //Remove dead bug from the vector
        }
        else
        {
            ++it;
        }
    }
}

bool Board::lastBugStanding()
{
    int count = 0;
    for(Bug* bug : bugVector)
    {
        if(bug->isAlive())
        {
            count++;
        }

        if(count == 1)
        {
            return false;
        }
    }
    return true;
}

void Board::runSimulation()
{
    bool gameOver = false;

    while(!gameOver)
    {
        tap();

        //Wait for 1 second before repeating
        this_thread::sleep_for(chrono::microseconds (1));

        if(lastBugStanding())
        {
            gameOver = true;
        }
        displayLifeHistory(cout);
    }
}
