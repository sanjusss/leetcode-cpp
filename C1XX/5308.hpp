#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minFlips(int a, int b, int c) 
    {
        int ans = 0;
        int bit;
        int ba;
        int bb;
        int bc;
        for (int i = 0; i <= 30; ++i)
        {
            bit = 1 << i;
            ba = a & bit;
            bb = b & bit;
            bc = c & bit;
            if ((ba | bb) == bc)
            {
                continue;
            }

            if (bc == bit)//1
            {
                ++ans;
            }
            else//0
            {
                if (ba == bit)
                {
                    ++ans;
                }

                if (bb == bit)
                {
                    ++ans;
                }
            }
        }

        return ans;
    }
};