#include <iostream>
#include "cmake-build-debug/headerFiles/Board.h"
using namespace std;

int main()
{
    Board board;

    board.initializeBugVector();
    //board.displayAllBugs();
    //board.displayAllCells();
    cout << endl;
    //board.tap();
    //board.displayAllBugs();
    //board.displayAllCells();
    board.findBug(101);
    return 0;
}
