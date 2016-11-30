#ifndef DIRECTMAPPED_H
#define DIRECTMAPPED_H
#include <iostream>


class directMapped
{
public:
    directMapped();
    void cache();

private:
    int addresses [27] = {4, 8, 20, 24, 28, 36, 44, 20, 24, 28, 36, 40, 44, 68, 72, 92, 96, 100, 104, 108, 112, 100, 112, 116, 120, 128, 140};
    //col 0 isvalid 1 is true 0 is false col 2 tag col 3 offset 4-7 data
    int table [4] [8];
    int address;
    int hits;
    int misses;
    int tag;
    int row;
    int offset;




};

#endif // DIRECTMAPPED_H
