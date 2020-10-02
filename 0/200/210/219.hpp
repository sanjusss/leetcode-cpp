#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> vi;
        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            if (vi.count(nums[i]) != 0 && i - vi[nums[i]] <= k)
            {
                return true;
            }

            vi[nums[i]] = i;
        }

        return false;
    }
};