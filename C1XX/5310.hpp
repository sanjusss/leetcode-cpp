#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int minimumDistance(string word) 
//    {
//        int size = word.size();
//        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(26, vector<int>(26, INT_MAX)));
//        dp[0] = vector<vector<int>>(26, vector<int>(26, 0));
//
//        int ans = INT_MAX;
//        for (int i = 1; i <= size; ++i)
//        {
//            int n = word[i - 1] - 'A';
//            for (int l = 0; l < 26; ++l)
//            {
//                for (int r = 0; r < 26; ++r)
//                {
//                    if (dp[i - 1][l][r] == INT_MAX)
//                    {
//                        continue;
//                    }
//
//                    dp[i][n][r] = min(dp[i][n][r], dp[i - 1][l][r] + distance(n, l));
//                    dp[i][l][n] = min(dp[i][l][n], dp[i - 1][l][r] + distance(n, r));
//                    
//                    if (i == size)
//                    {
//                        ans = min({ ans, dp[i][n][r], dp[i][l][n] });
//                    }
//                }
//            }
//        }
//
//        return ans;
//    }
//
//private:
//    int distance(int a, int b)
//    {
//        int xa = a % 6;
//        int ya = a / 6;
//        int xb = b % 6;
//        int yb = b / 6;
//        return abs(xa - xb) + abs(ya - yb);
//    }
//};

class Solution
{
public:
    int minimumDistance(string word)
    {
        vector<vector<int>> last(26, vector<int>(26, 0));
        vector<vector<int>> current(26, vector<int>(26, 0));
        vector<vector<int>> next(26, vector<int>(26, INT_MAX));

        int ans = INT_MAX;
        int size = word.size();
        for (int i = 1; i <= size; ++i)
        {
            last.swap(current);
            current.swap(next);

            int n = word[i - 1] - 'A';
            for (int l = 0; l < 26; ++l)
            {
                for (int r = 0; r < 26; ++r)
                {
                    next[l][r] = INT_MAX;
                    if (last[l][r] == INT_MAX)
                    {
                        continue;
                    }

                    current[n][r] = min(current[n][r], last[l][r] + distance(n, l));
                    current[l][n] = min(current[l][n], last[l][r] + distance(n, r));

                    if (i == size)
                    {
                        ans = min({ ans, current[n][r], current[l][n] });
                    }
                }
            }
        }

        return ans;
    }

private:
    int distance(int a, int b)
    {
        int xa = a % 6;
        int ya = a / 6;
        int xb = b % 6;
        int yb = b / 6;
        return abs(xa - xb) + abs(ya - yb);
    }
};