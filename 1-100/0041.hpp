#pragma once
#include "leetcode.h"

////空间复杂度O(n)
//class Solution 
//{
//public:
//    int firstMissingPositive(vector<int>& nums) 
//    {
//        int size = nums.size();
//        vector<int> exists(size + 1);
//        for (auto i : nums)
//        {
//            if (i <= size  && i > 0)
//            {
//                exists[i] = 1;
//            }
//        }
//
//        for (int i = 1; i <= size; ++i)
//        {
//            if (exists[i] == 0)
//            {
//                return i;
//            }
//        }
//
//        return size == 0 ? 1 : size + 1;
//    }
//};

//空间复杂度O(1)
class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            while (nums[i] != i + 1 &&
                nums[i] > 0 && nums[i] <= size && 
                nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return size + 1;
    }
};