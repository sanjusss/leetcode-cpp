#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans(1 << nums.size());
        ans[0]= {};
        int index = 0;
        for (auto& i : nums)
        {
            for (int j = index; j >= 0; --j)
            {
                ++index;
                ans[index] = ans[j];
                ans[index].push_back(i);
            }
        }

        return ans;
    }
};