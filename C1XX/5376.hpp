#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }

        sort(nums.rbegin(), nums.rend());

        vector<int> ans;
        int cur = 0;
        for (int i : nums)
        {
            cur += i;
            sum -= i;
            ans.push_back(i);
            if (cur > sum)
            {
                break;
            }
        }

        return ans;
    }
};