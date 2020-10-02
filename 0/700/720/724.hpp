#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        int left = 0;
        int right = 0;
        for (int n : nums)
        {
            right += n;
        }

        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            if (i > 0)
            {
                left += nums[i - 1];
            }

            right -= nums[i];
            if (left == right)
            {
                return i;
            }
        }

        return -1;
    }
};