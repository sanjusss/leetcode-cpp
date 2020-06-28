#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int minSubArrayLen(int s, vector<int>& nums) 
//    {
//        int length = nums.size();
//        int tempSum = 0;
//        int ml = INT_MAX;
//        for (int i = 0, j = 0; i < length; ++i)
//        {
//            if (i != 0)
//            {
//                tempSum -= nums[i - 1];
//            }
//
//            while (tempSum < s && j < length)
//            {
//                tempSum += nums[j++];
//            }
//
//            if (tempSum < s)
//            {
//                break;
//            }
//            else
//            {
//                ml = min(ml, j - i);
//            }
//        }
//
//        return ml == INT_MAX ? 0 : ml;
//    }
//};

//class Solution 
//{
//public:
//    int minSubArrayLen(int s, vector<int>& nums) 
//    {
//        int ans = INT_MAX;
//        int n = nums.size();
//        for (int i = 0; i < n; ++i)
//        {
//            int sum = 0;
//            for (int j = i; j < n; ++j)
//            {
//                sum += nums[j];
//                if (sum >= s)
//                {
//                    ans = min(ans, j - i + 1);
//                    break;
//                }
//            }
//        }
//
//        return ans == INT_MAX ? 0 : ans;
//    }
//};

//class Solution
//{
//public:
//    int minSubArrayLen(int s, vector<int>& nums)
//    {
//        int ans = INT_MAX;
//        int n = nums.size();
//        vector<int> sums(n + 1);
//        for (int i = 0; i < n; ++i)
//        {
//            sums[i + 1] = sums[i] + nums[i];
//        }
//
//        for (int i = 0; i < n; ++i)
//        {
//            auto pos = lower_bound(next(sums.begin(), i + 1), sums.end(), s + sums[i]);
//            if (pos != sums.end())
//            {
//                ans = min(ans, (int)distance(sums.begin(), pos) - i);
//            }
//        }
//
//        return ans == INT_MAX ? 0 : ans;
//    }
//};

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        while (end < n)
        {
            sum += nums[end];
            while (sum >= s)
            {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                ++start;
            }

            ++end;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};