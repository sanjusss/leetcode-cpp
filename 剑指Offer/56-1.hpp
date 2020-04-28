#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> singleNumbers(vector<int>& nums) 
    {
        int sum = 0;
        for (int i : nums)
        {
            sum ^= i;
        }

        int sign = 1;
        while ((sign & sum) == 0)
        {
            sign <<= 1;
        }

        int first = 0;
        int second = 0;
        for (int i : nums)
        {
            if (i & sign)
            {
                first ^= i;
            }
            else
            {
                second ^= i;
            }
        }

        return { first, second };
    }
};