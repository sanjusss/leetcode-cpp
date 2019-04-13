#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int arrayPairSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = nums.size() - 2; i >= 0; i -= 2)
        {
            sum += nums[i];
        }

        return sum;
    }
};