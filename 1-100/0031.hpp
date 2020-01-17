#pragma once
#include "leetcode.h"

class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.size() <= 1)
        {
            return;
        }

        for (auto i = prev(nums.end(), 1); i != nums.begin(); --i)
        {
            auto j = prev(i);
            if (*j < *i)
            {
                reverse(i, nums.end());
                i = upper_bound(i, nums.end(), *j);
                swap(*i, *j);
                return;
            }
        }

        reverse(nums.begin(), nums.end());
    }
};