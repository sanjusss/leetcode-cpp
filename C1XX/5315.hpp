#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maximum69Number(int num) 
    {
        int ans = 0;
        int n;
        bool changed = false;
        int base = 10000;
        for (int i = 0; i < 5; ++i)
        {
            n = num / base;
            num %= base;
            base /= 10;
            if (n == 6 && changed == false)
            {
                n = 9;
                changed = true;
            }

            ans = 10 * ans + n;
        }

        return ans;
    }
};