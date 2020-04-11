#pragma once
#include "leetcode.h"
//O(KNN)
//class Solution 
//{
//public:
//    int superEggDrop(int K, int N) 
//    {
//        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
//        for (int i = 1; i <= K; ++i)
//        {
//            for (int j = 1; j <= N; ++j)
//            {
//                dp[i][j] = j;
//                if (i == 1)
//                {
//                    continue;
//                }
//
//                for (int k = 1; k < j; ++k)
//                {
//                    dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][k - 1], dp[i][j - k]));
//                }
//            }
//        }
//
//        return dp[K][N];
//    }
//};

//O(KNlogN)
//class Solution
//{
//public:
//    int superEggDrop(int K, int N)
//    {
//        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
//        for (int i = 1; i <= K; ++i)
//        {
//            for (int j = 1; j <= N; ++j)
//            {
//                dp[i][j] = j;
//                if (i == 1 || j == 1)
//                {
//                    continue;
//                }
//
//                int left = 1;
//                int right = j;
//                while (left + 1 < right)
//                {
//                    int k = (left + right) / 2;
//                    if (dp[i - 1][k - 1] == dp[i][j - k])
//                    {
//                        right = k;
//                        left = k;
//                    }
//                    else if (dp[i - 1][k - 1] > dp[i][j - k])
//                    {
//                        right = k;
//                    }
//                    else
//                    {
//                        left = k;
//                    }
//                }
//
//                dp[i][j] = min(max(dp[i - 1][left - 1], dp[i][j - left]), max(dp[i - 1][right - 1], dp[i][j - right])) + 1;
//            }
//        }
//
//        return dp[K][N];
//    }
//};

//O(KN)
//class Solution
//{
//public:
//    int superEggDrop(int K, int N)
//    {
//        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
//        for (int i = 1; i <= K; ++i)
//        {
//            int k = 1;
//            for (int j = 1; j <= N; ++j)
//            {
//                dp[i][j] = j;
//                if (i == 1 || j == 1)
//                {
//                    continue;
//                }
//
//                while (k < j && max(dp[i - 1][k - 1], dp[i][j - k]) >= max(dp[i - 1][k], dp[i][j - k - 1]))
//                {
//                    ++k;
//                }
//
//                dp[i][j] = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);
//            }
//        }
//
//        return dp[K][N];
//    }
//};

//O(KN)
class Solution
{
public:
    int superEggDrop(int K, int N)
    {
        vector<int> dp(N + 1);
        for (int i = 0; i <= N; ++i)
        {
            dp[i] = i;
        }

        vector<int> dp2(N + 1);
        for (int i = 2; i <= K; ++i)
        {
            int k = 1;
            fill(dp2.begin(), dp2.end(), 0);
            for (int j = 1; j <= N; ++j)
            {
                while (k < j && max(dp[k - 1], dp2[j - k]) >= max(dp[k], dp2[j - k - 1]))
                {
                    ++k;
                }

                dp2[j] = 1 + max(dp[k - 1], dp2[j - k]);
            }

            dp.swap(dp2);
        }

        return dp[N];
    }
};