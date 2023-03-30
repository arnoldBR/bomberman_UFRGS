#include "tile_funcs.h"
#include "consts.h"

char GetTile(int x, int y, char sLevel[])
{
    if(x >= 0 && x < N_LEVEL_WDT && y >=0 && y < N_LEVEL_HGT)
        return sLevel[y * N_LEVEL_WDT + x];
    else return ' ';
}

void SetTile(int x, int y, int c, char sLevel[])
{
    if(x >= 0 && x < N_LEVEL_WDT && y >=0 && y < N_LEVEL_HGT)
        sLevel[y * N_LEVEL_WDT + x] = c;
}


