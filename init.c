#include "defs.h"

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64ToSq120[64];

void InitSq120To64()
{
    int index = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int sq = A1;
    int sq64 = 0;
    // iterating all squares and setting 65 as 65 should not be returneds . fail safe
    for (index = 0; index < BRD_SQ_NUM; ++index)
    {
        Sq120ToSq64[index] = 65;
    }

    // interating all squares and setting 120 as t should be not returned . fail safe
    for (index = 0; index < 64; ++index)
    {
        Sq64ToSq120[index] = 120;
    }

    // resetting the squares to correct numbers
    for (rank = RANK_1; rank <= RANK_8; ++rank)
    {
        for (file = FILE_A; file <= FILE_H; ++file)
        {
            sq = FR2SQ(file, rank);
            Sq64ToSq120[sq64] = sq;
            Sq120ToSq64[sq] = sq64;
            sq64++;
        }
    }
}

void AllInit()
{
    InitSq120To64();
}