#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minimumSwap(string s1, string s2) 
    {
        int length = s1.length();
        int x = 0;
        int y = 0;
        for (int i = 0; i < length; ++i)
        {
            if (s1[i] == s2[i])
            {
                continue;
            }

            if (s1[i] == 'x')
            {
                ++x;
            }
            else
            {
                ++y;
            }
        }

        int res = x / 2 + y / 2;
        int rx = x % 2;
        int ry = y % 2;
        if (rx != ry)
        {
            return -1;
        }

        if (rx == 1)
        {
            res += 2;
        }

        return res;
    }
};