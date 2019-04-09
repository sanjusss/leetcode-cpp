#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
        int n = x ^ y;
        int judge = 1;
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            if ((n >> i) & judge)
            {
                ++res;
            }
        }

        return res;
    }
};