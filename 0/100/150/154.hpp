#pragma once
#include "leetcode.h"

//class Solution
//{
//public:
//    int findMin(vector<int>& nums)
//    {
//        for (int i = nums.size() - 1; i > 0; --i)
//        {
//            if (nums[i] < nums[i - 1])
//            {
//                return nums[i];
//            }
//        }
//
//        return nums[0];
//    }
//};

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == nums[right])
            {
                --right;
            }
            else if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return nums[left];
    }
};