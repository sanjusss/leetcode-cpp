#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int s1 = nums1.size();
        int s2 = nums2.size();
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, INT_MIN / 2));
        int temp;
        for (int i = 1; i <= s1; ++i)
        {
            for (int j = 1; j <= s2; ++j)
            {
                temp = nums1[i - 1] * nums2[j - 1];
                dp[i][j] = max({ dp[i - 1][j - 1] + temp, temp, dp[i - 1][j], dp[i][j - 1] });
            }
        }

        return dp[s1][s2];
    }
};