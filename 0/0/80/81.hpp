#pragma once
#include "leetcode.h"

class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        if (nums.empty())
        {
            return false;
        }

        int start = nums.front();
        int end = nums.back();
        if (target > end && target < start)
        {
            return false;
        }

        if (target == start || target == end)
        {
            return true;
        }

        int left = 0;
        int right = nums.size() - 1;
        while (left != right && nums[left] == end)
        {
            ++left;
        }

        int mid;
        if (target <= end)
        {
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (nums[mid] == target)
                {
                    return true;
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
                    return true;
                }
                else if (nums[mid] <= end || nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }

        return false;
    }
};