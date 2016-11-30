#include "fullyassociative.h"

fullyAssociative::fullyAssociative()
{
    hits = 0;
    misses = 0;
    hit = false;

}

void fullyAssociative::Pass()
{
    hits = 0;
    misses = 0;

    for(int i = 0; i < 27; i++)
    {
        //std::cout << "address "<< addresses[i] << std::endl;
        int current = addresses[i];
        rowWithLowestLRU = 0;
        int nonValidRow = -1;
        row = i;
        hit = false;
        for(int j = 7; j >= 0; j--)
        {

            if(table [j] [0] == 1)
            {
                if(table [j] [2] == addresses[i])
                {
                    hits++;
                    table [j] [1]++;
                    hit = true;
                    std::cout << "address "<< addresses[i] << " Hits into row " << j << std::endl;
                }
                else
                {
                    if(table [j] [1] < table [rowWithLowestLRU] [1])
                    {
                        rowWithLowestLRU = j;
                    }

                }
            }
            else
            {
                nonValidRow = j;
            }
        }
        if(!hit && nonValidRow == -1)
        {
            table [rowWithLowestLRU] [2] = addresses[i];
            table [rowWithLowestLRU] [0] = 1;
            table [rowWithLowestLRU] [1] = 1;
            std::cout << "address "<< addresses[i] << " misses into row " << rowWithLowestLRU << std::endl;
            misses++;

        }
        else if(!hit && nonValidRow >= 0)
        {
            table [nonValidRow] [2] = addresses[i];
            table [nonValidRow] [0] = 1;
            table [nonValidRow] [1] = 1;
            std::cout << "address "<< addresses[i] << " misses into row " << nonValidRow << std::endl;
            misses++;
        }



    }

    std::cout<< hits << " hits , " << misses << " misses" << std::endl;

}

int fullyAssociative::returnTable(int x, int y)
{
    return table[x][y];

}

double fullyAssociative::calculate(){
    return (hits + misses*28)/27;

}
