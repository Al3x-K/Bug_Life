#include <iostream>
#include <fstream>
#include "cmake-build-debug/headerFiles/Board.h"
using namespace std;

void displayMenu();
int main()
{
    Board board;
    int choice;
    int id;
    do
    {
        displayMenu();
        cout << endl;
        cout << "Enter command: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                board.initializeBugVector();
                break;
            case 2:
                board.displayAllBugs();
                break;
            case 3:
                cout << "Enter id: ";
                cin >> id;
                board.findBug(id);
                break;
            case 4:
                board.tap();
                break;
            case 5:
                board.displayLifeHistory(cout);
                break;
            case 6:
                board.displayAllCells();
                break;
            case 7:
                board.runSimulation();
                break;
            case 8:
                ofstream out("bugs_life_history_date_time.out.txt");
                board.displayLifeHistory(out);
                choice = 9;
                break;
        }
        cout << endl;
    }
    while(choice != 9);

    return 0;
}

void displayMenu()
{
    cout << "Menu items:" << endl;
    cout << "1. Initialize Bug Board (load data from file)" << endl;
    cout << "2. Display all Bugs. " << endl;
    cout << "3. Find a Bug (given an id)" << endl;
    cout << "4. Tap the Bug Board" << endl;
    cout << "5. Display Life History of all Bugs" << endl;
    cout << "6. Display all Cells listing their Bugs " << endl;
    cout << "7. Run simulation (generates a Tap every second)" << endl;
    cout << "8. Exit (Write Life History to file)" << endl;
}

