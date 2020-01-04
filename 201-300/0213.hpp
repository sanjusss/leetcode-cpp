#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int size = nums.size();
        if (size == 0)
        {
            return 0;
        }
        else if (size == 1)
        {
            return nums[0];
        }

        vector<int> dpNot1(size + 1, 0);
        vector<int> dpIn1(size + 1, 0);
        dpIn1[1] = nums[0];
        for (int i = 2; i < size; ++i)
        {
            dpNot1[i] = max(dpNot1[i - 1], dpNot1[i - 2] + nums[i - 1]);
            dpIn1[i] = max(dpIn1[i - 1], dpIn1[i - 2] + nums[i - 1]);
        }

        dpNot1[size] = max(dpNot1[size - 1], dpNot1[size - 2] + nums[size - 1]);
        dpIn1[size] = dpIn1[size - 1];
        return max(dpNot1[size], dpIn1[size]);
    }
};