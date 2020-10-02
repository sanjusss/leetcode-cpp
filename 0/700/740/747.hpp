#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int dominantIndex(vector<int>& nums) 
    {
        int max1 = -1;
        int max2 = -1;
        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            if (max2 == -1 || nums[i] > nums[max2])
            {
                if (max1 == -1 || nums[i] > nums[max1])
                {
                    max2 = max1;
                    max1 = i;
                }
                else
                {
                    max2 = i;
                }
            }
        }

        return (max1 == -1 || (max2 != -1 && nums[max1] < 2 * nums[max2])) ? -1 : max1;
    }
};