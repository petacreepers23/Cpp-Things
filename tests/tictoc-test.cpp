#include "../include/utilityTimer.hpp"


using namespace P23;

int main () {

    TicToc timer;
    timer.tic();
    for (int i = 0; i < 10000000; ++i);
    timer.toc();

    //QuickTicToc quickTimer;
    //for (int i = 0; i < 10000000; ++i);
    //quickTimer.~QuickTicToc();

    QuickTicToc *q = new QuickTicToc;
    for (int i = 0; i < 10000000; ++i);
    delete q;

    auto t = new QuickTicToc;
    for (int i = 0; i < 10000000; ++i);
    delete t;
}
