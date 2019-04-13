#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int length = nums.size();
        int tempSum = 0;
        int ml = INT_MAX;
        for (int i = 0, j = 0; i < length; ++i)
        {
            if (i != 0)
            {
                tempSum -= nums[i - 1];
            }

            while (tempSum < s && j < length)
            {
                tempSum += nums[j++];
            }

            if (tempSum < s)
            {
                break;
            }
            else
            {
                ml = min(ml, j - i);
            }
        }

        return ml == INT_MAX ? 0 : ml;
    }
};