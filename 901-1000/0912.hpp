#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        return nums;
    }
};