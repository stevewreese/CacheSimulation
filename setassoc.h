#ifndef SETASSOC_H
#define SETASSOC_H
#include <iostream>


class setAssoc
{
public:
    setAssoc();
    void cache();

private:
    int addresses [27] = {4, 8, 20, 24, 28, 36, 44, 20, 24, 28, 36, 40, 44, 68, 72, 92, 96, 100, 104, 108, 112, 100, 112, 116, 120, 128, 140};
    //col 0 isvalid 1 is true 0 is false col 1 lsu 1 col 2 tag 1 col 3 lsu 2 col 4 tag 2
    int table [4] [5];
    int address;
    int hits;
    int misses;
    int tag;
    int index;
    int offset;
    int lsuCurrentCol;
    int lsuLowestCol;
    bool hit;
};

#endif // SETASSOC_H
