#pragma once
#include "leetcode.h"

class Solution 
{
public:
    //调用标准库
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> res;
        unordered_set<int> un1(nums1.begin(), nums1.end());
        for (auto i : nums2)
        {
            if (un1.count(i) > 0)
            {
                res.insert(i);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};