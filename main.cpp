#include <iostream>
#include <fstream>
#include "cmake-build-debug/headerFiles/Board.h"
using namespace std;

int main()
{
    Board board;

    board.initializeBugVector();
    board.displayAllBugs();
    cout << endl;
    board.displayAllCells();
    cout << endl;
    board.tap();
    board.displayAllCells();
    board.tap();
    board.displayAllCells();
    board.tap();
    board.displayAllCells();
    board.tap();
    board.displayAllCells();
    board.displayAllBugs();
    cout << endl;
    board.displayLifeHistory(cout);
    //ofstream out("bugs_life_history_date_time.out.txt");
    //board.displayLifeHistory(out);
    //board.displayAllCells();
    cout << endl;
    //board.findBug(101);
    return 0;
}
