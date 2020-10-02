#pragma once
#include "leetcode.h"

//伪装成动态规划的穷举
//class Solution 
//{
//public:
//    int jump(vector<int>& nums) 
//    {
//        int size = nums.size();
//        vector<int> dp(size, 0);
//        int maxEnd = 0;
//        for (int i = 0; i < size - 1; ++i)
//        {
//            int end = min(size - 1, i + nums[i]);
//            if (end <= maxEnd)
//            {
//                continue;
//            }
//            else
//            {
//                maxEnd = end;
//            }
//
//            for (int j = i + 1; j <= end; ++j)
//            {
//                if (dp[j] == 0 || dp[j] > dp[i])
//                {
//                    dp[j] = dp[i] + 1;
//                }
//            }
//        }
//
//        return dp[nums.size() - 1];
//    }
//};

//O(n)的算法
//class Solution
//{
//public:
//    int jump(vector<int>& nums)
//    {
//        int end = nums.size() - 1;
//        int ans = 0;
//        int i = -1;
//        int maxi = 0;
//        while (i < end && maxi < end)
//        {
//            int jend = maxi;
//            for (int j = i + 1; j <= jend; ++j)
//            {
//                if (j + nums[j] > maxi)
//                {
//                    maxi = j + nums[j];
//                }
//            }
//
//            i = jend;
//            ++ans;
//        }
//
//        return ans;
//    }
//};

//对上面的简化
class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int end = 0;
        int maxPosition = 0;
        int steps = 0;
        for (int i = 0; i < nums.size() - 1; i++) 
        {
            //找能跳的最远的
            maxPosition = max(maxPosition, nums[i] + i);
            if (i == end) 
            { //遇到边界，就更新边界，并且步数加一
                end = maxPosition;
                steps++;
            }
        }
        return steps;
    }
};