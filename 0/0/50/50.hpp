#pragma once
#include "leetcode.h"

class Solution 
{
public:
    double myPow(double x, int n) 
    {
        long size = n;
        if (size < 0)
        {
            x = 1 / x;
            size = -size;
        }

        double res = 1;
        long bit = 1;
        for (int i = 0; i < 32; ++i)
        {
            if (bit & size)
            {
                res *= x;
            }

            bit <<= 1;
            x = x * x;
        }

        return res;
    }
};