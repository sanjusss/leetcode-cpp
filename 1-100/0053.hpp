#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int current = INT_MIN;
        int sum = INT_MIN;
        for (int i : nums)
        {
            if (current < 0)
            {
                current = i;
            }
            else
            {
                current += i;
            }

            sum = max(current, sum);
        }

        return sum;
    }

    //耗时更长的分治法
    //int maxSubArray(vector<int>& nums)
    //{
    //    return div(nums, 0, nums.size() - 1);
    //}

    //int div(vector<int>& nums, int start, int end)
    //{
    //    if (start >= end)
    //    {
    //        return nums[start];
    //    }

    //    int mid = (end - start) / 2 + start;
    //    return max({ div(nums, start, mid),
    //        div(nums, mid + 1, end),
    //        maxMidSum (nums, start, end, mid)});
    //}

    //int maxMidSum(vector<int>& nums, int start, int end, int mid)
    //{
    //    int leftTemp = nums[mid];
    //    int leftSum = leftTemp;
    //    for (int i = mid - 1; i >= start; --i)
    //    {
    //        leftTemp += nums[i];
    //        leftSum = max(leftSum, leftTemp);
    //    }

    //    int rightTemp = 0;
    //    int rightSum = rightTemp;
    //    for (int i = mid + 1; i <= end; ++i)
    //    {
    //        rightTemp += nums[i];
    //        rightSum = max(rightSum, rightTemp);
    //    }

    //    return leftSum + rightSum;
    //}
};