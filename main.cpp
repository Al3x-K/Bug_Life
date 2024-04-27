#include <iostream>
#include <fstream>
#include "cmake-build-debug/headerFiles/Board.h"
using namespace std;

int main()
{
    Board board;

    board.initializeBugVector();
    board.displayAllBugs();

    board.tap();
    board.tap();
    board.tap();
    board.tap();
    board.tap();
    board.tap();

    cout << endl;
    board.displayLifeHistory(cout);
    ofstream out("bugs_life_history_date_time.out.txt");
    cout << endl;
    board.displayAllBugs();
    board.displayLifeHistory(out);

    board.findBug(113);
    return 0;
}
