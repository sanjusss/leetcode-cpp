#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int findNumbers(vector<int>& nums) 
    {
        int res = 0;
        for (int i : nums)
        {
            int size = 0;
            while (i > 0)
            {
                ++size;
                i /= 10;
            }

            if (size % 2 == 0)
            {
                ++res;
            }
        }

        return res;
    }
};