#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int expectNumber(vector<int>& scores) 
    {
        unordered_set<int> nums(scores.begin(), scores.end());
        return nums.size();
    }
};