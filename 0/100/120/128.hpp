#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        int res = 0;
        for (int i : uniqueNums)
        {
            if (uniqueNums.find(i - 1) != uniqueNums.end())
            {
                continue;
            }

            int length = 1;
            while (uniqueNums.find(i + 1) != uniqueNums.end())
            {
                ++i;
                ++length;
            }

            res = max(res, length);
        }

        return res;
    }
};