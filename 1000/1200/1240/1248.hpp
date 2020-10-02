#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int numberOfSubarrays(vector<int>& nums, int k) 
//    {
//        int n = nums.size();
//        vector<int> odds;
//        for (int i = 0; i < n; ++i)
//        {
//            if (nums[i] % 2 == 1)
//            {
//                odds.push_back(i);
//            }
//        }
//
//        if (odds.size() < k)
//        {
//            return 0;
//        }
//
//        int ans = 0;
//        int maxi = odds.size() - 1;
//        for (int i = k - 1; i <= maxi; ++i)
//        {
//            int left = 0;
//            if (i < k)
//            {
//                left = odds[0] + 1;
//            }
//            else
//            {
//                left = odds[i - k + 1] - odds[i - k];
//            }
//
//            int right = 0;
//            if (i == maxi)
//            {
//                right = n - odds[i];
//            }
//            else
//            {
//                right = odds[i + 1] - odds[i];
//            }
//
//            ans += left * right;
//        }
//
//        return ans;
//    }
//};

//class Solution
//{
//public:
//    int numberOfSubarrays(vector<int>& nums, int k)
//    {
//        int n = nums.size();
//        vector<int> odds;
//        odds.push_back(-1);
//        for (int i = 0; i < n; ++i)
//        {
//            if (nums[i] & 1)
//            {
//                odds.push_back(i);
//            }
//        }
//
//        odds.push_back(n);
//        int ans = 0;
//        int maxi = odds.size() - 2;
//        for (int i = k; i <= maxi; ++i)
//        {
//            ans += (odds[i - k + 1] - odds[i - k]) * (odds[i + 1] - odds[i]);
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> cnt(n + 1);
        cnt[0] = 1;
        int ans = 0;
        int odds = 0;
        for (int i : nums)
        {
            odds += i & 1;
            ++cnt[odds];
            if (odds >= k)
            {
                ans += cnt[odds - k];
            }
        }

        return ans;
    }
};