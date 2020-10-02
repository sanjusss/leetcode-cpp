#pragma once
#include "leetcode.h"

//class Solution
//{
//public:
//    int subarraySum(vector<int>& nums, int k)
//    {
//        int ans = 0;
//        int size = nums.size();
//        int sum;
//        for (int i = 0; i < size; ++i)
//        {
//            sum = 0;
//            for (int j = i; j < size; ++j)
//            {
//                sum += nums[j];
//                if (sum == k)
//                {
//                    ++ans;
//                }
//            }
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> sums;
        sums[0] = 1;
        for (int i : nums)
        {
            sum += i;
            if (sums.find(sum - k) != sums.end())
            {
                ans += sums[sum - k];
            }

            ++sums[sum];
        }

        return ans;
    }
};