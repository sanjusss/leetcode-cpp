#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int maxScore(vector<int>& cardPoints, int k) 
//    {
//        return maxScore(cardPoints, 0, cardPoints.size() - 1, k);
//    }
//
//private:
//    int maxScore(vector<int>& cardPoints, int left, int right, int k)
//    {
//        if (k == 0)
//        {
//            return 0;
//        }
//
//        return max(cardPoints[left] + maxScore(cardPoints, left + 1, right, k - 1),
//            cardPoints[right] + maxScore(cardPoints, left, right - 1, k - 1));
//    }
//};

//class Solution
//{
//public:
//    int maxScore(vector<int>& cardPoints, int k)
//    {
//        int n = cardPoints.size();
//        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
//        //dp[i][j] = max(dp[i - 1][j - 1] + cardPoints[i - 1], dp[j][j])
//        for (int i = 1; i <= n; ++i)
//        {
//            for (int j = 1; j <= k; ++j)
//            {
//                if (i < j)
//                {
//                    continue;
//                }
//
//                dp[i][j] = max(dp[i - 1][j - 1] + cardPoints[i - 1], dp[j][j]);
//            }
//        }
//
//        return dp[n][k];
//    }
//};

//class Solution
//{
//public:
//    int maxScore(vector<int>& cardPoints, int k)
//    {
//        int n = cardPoints.size();
//        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
//        //dp[i][j] = max(dp[i - 1][j - 1] + cardPoints[i - 1], dp[j][j])
//        for (int j = 1; j <= k; ++j)
//        {
//            dp[j][j] = dp[j - 1][j - 1] + cardPoints[j - 1];
//            for (int i = j + 1; i <= n; ++i)
//            {
//                dp[i][j] = max(dp[i - 1][j - 1] + cardPoints[i - 1], dp[j][j]);
//            }
//        }
//
//        return dp[n][k];
//    }
//};

//class Solution
//{
//public:
//    int maxScore(vector<int>& cardPoints, int k)
//    {
//        int n = cardPoints.size();
//        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
//        //dp[i][j] = max(dp[i - 1][j - 1] + cardPoints[i - 1], dp[j][j])
//        for (int j = 1; j <= k; ++j)
//        {
//            dp[j][j] = dp[j - 1][j - 1] + cardPoints[j - 1];
//            int i = n - k + j;
//            dp[i][j] = max(dp[i - 1][j - 1] + cardPoints[i - 1], dp[j][j]);
//        }
//
//        return dp[n][k];
//    }
//};

class Solution
{
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int n = cardPoints.size();
        int dp = 0;
        int sum = 0;
        for (int j = 1; j <= k; ++j)
        {
            sum += cardPoints[j - 1];
            dp = max(dp + cardPoints[n - k + j - 1], sum);
        }

        return dp;
    }
};