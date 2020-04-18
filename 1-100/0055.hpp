#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int best = 0;
        int n = nums.size();
        for (int i = 0; i < n && i <= best; ++i)
        {
            best = max(best, i + nums[i]);
        }

        return best >= n - 1;
    }
};