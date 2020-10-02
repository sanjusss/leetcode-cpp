#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int lengthOfLIS(vector<int>& nums) 
//    {
//        int size = nums.size();
//        int res = 0;
//        unordered_map<int, int> dp;
//        for (int i = 0; i < size; ++i)
//        {
//            int length = 0;
//            for (auto j = dp.begin(); j != dp.end(); ++j)
//            {
//                if (nums[i] > j->first)
//                {
//                    length = max(length, j->second);
//                }
//            }
//
//            dp[nums[i]] = max(dp[nums[i]], length + 1);
//            res = max(res, dp[nums[i]]);
//        }
//
//        return res;
//    }
//};

//class Solution
//{
//public:
//    int lengthOfLIS(vector<int>& nums)
//    {
//        int size = nums.size();
//        int res = 0;
//        vector<int> dp(size, 0);
//        for (int i = 0; i < size; ++i)
//        {
//            int length = 0;
//            for (int j = 0; j < i; ++j)
//            {
//                if (nums[i] > nums[j])
//                {
//                    length = max(dp[j], length);
//                }
//            }
//
//            dp[i] = length + 1;
//            res = max(res, dp[i]);
//        }
//
//        return res;
//    }
//};
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int length = 1;
        vector<int> dp(nums.size(), INT_MAX);
        for (int i : nums)
        {
            auto end = next(dp.begin(), length);
            auto pos = lower_bound(dp.begin(), end, i);
            *pos = i;
            if (pos == end)
            {
                ++length;
            }
        }

        return length;
    }
};