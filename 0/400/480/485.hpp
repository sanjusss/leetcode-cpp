#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int length = 0;
        int current = 0;
        for (int i : nums)
        {
            if (i == 0)
            {
                length = max(length, current);
                current = 0;
            }
            else
            {
                ++current;
            }
        }

        length = max(length, current);
        return length;
    }
};