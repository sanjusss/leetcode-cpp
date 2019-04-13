#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n = 0;
        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            if (nums[i] != val)
            {
                nums[n++] = nums[i];
            }
        }

        return n;
    }
};