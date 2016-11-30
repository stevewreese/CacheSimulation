#include "setassoc.h"

setAssoc::setAssoc()
{
    for(int s = 0; s < 4; s++)
    {
        for(int t = 0; t < 5; t++)
        {
            table[s][t] = 0;

        }
    }

}

void setAssoc::cache()
{
    hits = 0;
    misses = 0;

    for(int i = 0; i < 27; i++)
    {
        address = addresses[i];
        tag = address/32;
        index = (address/8)%4;
        offset = address%8;
        hit = false;
        //std::cout << "address " << address << " tag " << tag << " index " << index << " offset " << offset << std::endl;

        if(table[index][0] == 1)
        {
            for(int j = 2; j < 5; j = j + 2){
                if(table[index][j] == tag)
                {
                    hits ++;
                    table[index][j - 1]++;
                    //table[index][j]
                    hit = true;
                    break;
                    std::cout << "Accessing " << address << "(tag " << tag << "): Hit from row  " << index << std::endl;
                }
            }
            if(!hit)
            {
                for(int k = 1; k < 5; k = k + 2)
                {
                    lsuCurrentCol = k;
                    lsuLowestCol = k;

                    if(table[index][lsuCurrentCol] > table[index][lsuCurrentCol + 2])
                    {
                        lsuLowestCol = k + 2;

                    }
                }
                misses ++;
                table[index][lsuLowestCol + 1] = tag;
                table[index][lsuLowestCol] = 1;

                std::cout << "Accessing " << address << "(tag " << tag << "): miss - cached to row  " << index << std::endl;

            }
        }
        else
        {
            misses ++;
            table[index][0] = 1;
            table[index][1] = 1;
            table[index][3] = 0;
            table[index][2] = tag;
            std::cout << "Accessing " << address << "(tag " << tag << "): miss - cached to row  " << index << std::endl;
        }
         //std::cout << "i " << i << std::endl;

    }
    std::cout << "hits " << hits << " misses " << misses << std::endl;
}

