#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        uint32_t judge = 1;
        int res = 0;
        for (uint32_t i = 0; i < 32; ++i)
        {
            if ((n >> i) & judge)
            {
                ++res;
            }
        }

        return res;
    }
};