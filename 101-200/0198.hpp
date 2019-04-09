#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n <= 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return nums[0];
        }

        int prev2 = 0;
        int prev1 = nums[0];
        int res = prev1;
        for (int i = 1; i < n; ++i)
        {
            res = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = res;
        }

        return res;
    }
};