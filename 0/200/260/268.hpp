#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int length = nums.size();
        int res = length;
        for (int i = 0; i < length; ++i)
        {
            res ^= i;
            res ^= nums[i];
        }

        return res;
    }
};