#ifndef FULLYASSOCIATIVE_H
#define FULLYASSOCIATIVE_H
#include <array>
#include <iostream>


class fullyAssociative
{
public:
    fullyAssociative();
    void Pass();
    int returnTable(int x, int y);
    double calculate();

private:
    int addresses [27] = {4, 8, 20, 24, 28, 36, 44, 20, 24, 28, 36, 40, 44, 68, 72, 92, 96, 100, 104, 108, 112, 100, 112, 116, 120, 128, 140};
    //col 1 isvalid 1 is true 0 is false 2 lru 3 tag
    int table [8] [3];
    int hits;
    int misses;
    int row;
    int rowWithLowestLRU;
    bool hit;


};

#endif // FULLYASSOCIATIVE_H
