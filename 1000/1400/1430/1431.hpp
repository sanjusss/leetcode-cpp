#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int val = INT_MIN;
        for (int i : candies)
        {
            val = max(val, i);
        }

        vector<bool> ans;
        for (int i : candies)
        {
            ans.push_back(i + extraCandies >= val);
        }

        return ans;
    }
};