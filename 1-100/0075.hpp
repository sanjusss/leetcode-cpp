#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    void sortColors(vector<int>& nums) 
//    {
//        int freq[3] = { 0 };
//        for (auto i : nums)
//        {
//            ++freq[i];
//        }
//
//        auto begin = nums.begin();
//        auto end = begin;
//        for (int i = 0; i < 3; ++i)
//        {
//            end = next(begin, freq[i]);
//            fill(begin, end, i);
//            begin = end;
//        }
//    }
//};

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int p0 = 0;
        int p2 = nums.size() - 1;
        int cur = p0;
        while (cur <= p2)
        {
            if (nums[cur] == 0)
            {
                swap(nums[cur], nums[p0]);
                ++p0;
                ++cur;
            }
            else if (nums[cur] == 1)
            {
                ++cur;
            }
            else
            {
                swap(nums[cur], nums[p2]);
                --p2;
            }
        }
    }
};