#include "directmapped.h"

directMapped::directMapped()
{
    hits = 0;
    misses = 0;

}


void directMapped::cache()
{
    for(int i = 0; i < 27; i++)
    {
        address = addresses[i];
        tag = address/64;
        row = (address/16)%4;
        offset = address%16;
        std::cout << "address " << address << " row " << row << " tag " << tag << " offset " << offset << std::endl;



    }

}
