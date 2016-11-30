#include "directmapped.h"

directMapped::directMapped()
{
    hits = 0;
    misses = 0;

}


void directMapped::cache()
{
    hits = 0;
    misses = 0;
    for(int i = 0; i < 27; i++)
    {
        address = addresses[i];
        tag = address/64;
        row = (address/16)%4;
        offset = address%16;
        //std::cout << "address " << address << " row " << row << " tag " << tag << " offset " << offset << std::endl;
        if(table[row][0] == 1)
        {
            if(table[row][1] == tag)
            {
                hits ++;
                std::cout << "Accessing " << address << "(tag " << tag << "): Hit from row  " << row << std::endl;
            }
            else {
                misses ++;
                table[row][1] = tag;
                std::cout << "Accessing " << address << "(tag " << tag << "): miss - cached to row  " << row << std::endl;
            }
        }
        else
        {
            misses ++;
            table[row][0] = 1;
            table[row][1] = tag;
            std::cout << "Accessing " << address << "(tag " << tag << "): miss - cached to row  " << row << std::endl;
        }
        std::cout << "hits " << hits << " misses " << misses << std::endl;



    }

}
