#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
            {
                ans[i] = nums[i];
            }
            else
            {
                ans[i] = ans[i - 1] * nums[i];
            }
        }

        int R = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (i == 0)
            {
                ans[i] = R;
            }
            else
            {
                ans[i] = ans[i - 1] * R;
                R *= nums[i];
            }
        }

        return ans;
    }
};