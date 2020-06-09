#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int translateNum(int num) 
    {
        int cur = 100;
        int prev = 0;
        int curCount = 1;
        int prevCount = 1;
        int temp;
        while (num > 0)
        {
            prev = cur;
            cur = num % 10;
            num /= 10;
            if (cur * 10 + prev > 25 || cur * 10 + prev < 10)
            {
                prevCount = curCount;
            }
            else
            {
                temp = prevCount + curCount;
                prevCount = curCount;
                curCount = temp;
            }
        }

        return curCount;
    }
};