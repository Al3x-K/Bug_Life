#include <iostream>
#include "cmake-build-debug/headerFiles/Board.h"
using namespace std;

int main() {
    Board board;

    board.initializeBugVector();
    board.displayAllBugs();
    board.displayAllCells();

    return 0;
}
