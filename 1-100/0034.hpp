#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.size() == 0)
        {
            return { -1, -1 };
        }

        int left = leftBound(nums, 0, nums.size() - 1, target);
        if (left == -1)
        {
            return { -1, -1 };
        }
        else
        {
            return { left, rightBound(nums, left, nums.size() - 1, target) };
        }
    }

private:
    int leftBound(vector<int>& nums, int left, int right, int target)
    {
        while (left + 1 < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        if (nums[left] == target)
        {
            return left;
        }
        else if (nums[right] == target)
        {
            return right;
        }
        else
        {
            return -1;
        }
    }

    int rightBound(vector<int>& nums, int left, int right, int target)
    {
        while (left + 1 < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        if (nums[right] == target)
        {
            return right;
        }
        else if(nums[left] == target)
        {
            return left;
        }
        else
        {
            return -1;
        }
    }
};