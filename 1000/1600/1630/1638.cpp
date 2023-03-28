/*
 * @Author: sanjusss
 * @Date: 2023-03-27 08:57:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-28 08:55:48
 * @FilePath: \1000\1600\1630\1638.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        iota(dp[0].begin(), dp[0].end(), 0);
        for (int i = 0; i < len1; ++i) {
            dp[i + 1][0] = i + 1;
            for (int j = 0; j < len2; ++j) {
                dp[i + 1][j + 1] = min({ dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + 2 });
                if (str1[i] == str2[j]) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }

        string ans;
        int i = len1;
        int j = len2;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1] && dp[i][j] - 1 == dp[i - 1][j - 1]) {
                ans.push_back(str1[--i]);
                --j;
            }
            else if (dp[i][j] - 1 == dp[i - 1][j]) {
                ans.push_back(str1[--i]);
            }
            else if (dp[i][j] - 1 == dp[i][j - 1]) {
                ans.push_back(str2[--j]);
            }
            else {
                ans.push_back(str1[--i]);
                ans.push_back(str2[--j]);
            }
        }

        while (i > 0) {
            ans.push_back(str1[--i]);
        }

        while (j > 0) {
            ans.push_back(str2[--j]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

TEST(&Solution::shortestCommonSupersequence)