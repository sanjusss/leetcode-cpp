#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int search(vector<int>& nums, int target) 
//    {
//        int div = findDiv(nums);
//        int res = search(nums, target, 0, div);
//        if (res == -1)
//        {
//            res = search(nums, target, div + 1, nums.size() - 1);
//        }
//
//        return res;
//    }
//
//private:
//    int search(vector<int>& nums, int target, int left, int right)
//    {
//        while (left <= right)
//        {
//            int mid = (left + right) / 2;
//            if (nums[mid] == target)
//            {
//                return mid;
//            }
//            else if (nums[mid] > target)
//            {
//                right = mid - 1;
//            }
//            else
//            {
//                left = mid + 1;
//            }
//        }
//
//        return -1;
//    }
//
//    int findDiv(vector<int>& nums)
//    {
//        int left = 0;
//        int right = nums.size() - 2;
//        while (left <= right)
//        {
//            int mid = (left + right) / 2;
//            if (nums[mid] > nums[mid + 1])
//            {
//                return mid;
//            }
//            else if (nums[mid] < nums[0])
//            {
//                right = mid - 1;
//            }
//            else
//            {
//                left = mid + 1;
//            }
//        }
//
//        return -1;
//    }
//};

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.empty())
        {
            return -1;
        }

        int start = nums.front();
        int end = nums.back();
        if (target > end && target < start)
        {
            return -1;
        }

        int left = 0;
        int right = nums.size() - 1;
        int mid;
        if (target <= end)
        {
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] > end || nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        else
        {
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] < end || nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};