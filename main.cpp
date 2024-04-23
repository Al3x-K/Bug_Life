#include <iostream>
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
    board.displayAllBugs();
    cout << endl;
    board.displayLifeHistory();
    //board.displayAllCells();
    cout << endl;
    board.findBug(101);
    return 0;
}
