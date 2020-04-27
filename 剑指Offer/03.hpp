#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int findRepeatNumber(vector<int>& nums) 
//    {
//        vector<bool> used(nums.size());
//        for (auto i : nums)
//        {
//            if (used[i])
//            {
//                return i;
//            }
//            else
//            {
//                used[i] = true;
//            }
//        }
//
//        return -1;
//    }
//};

class Solution
{
public:
    int findRepeatNumber(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            while (i != nums[i])
            {
                if (nums[i] == nums[nums[i]])
                {
                    return nums[i];
                }

                swap(nums[i], nums[nums[i]]);
            }
        }

        return -1;
    }
};