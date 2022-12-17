/*
 * @Author: sanjusss
 * @Date: 2022-12-16 08:41:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-16 10:57:22
 * @FilePath: \0\400\470\471.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                int size = j - i + 1;
                if (dp[i][j].empty() || dp[i][j].size() >= j - i + 1) {
                    dp[i][j] = s.substr(i, j - i + 1);
                }

                for (int k = i + 1; k <= j; ++k) {
                    if (dp[i][k - 1].size() + dp[k][j].size() < dp[i][j].size()) {
                        dp[i][j] = dp[i][k - 1] + dp[k][j];
                    }
                }

                for (int k = 2;  i + k * size <= n; ++k) {
                    bool success = true;
                    int start = i + (k - 1) * size;
                    for (int c = 0; c < size; ++c) {
                        if (s[i + c] != s[start + c]) {
                            success = false;
                            break;
                        }
                    }

                    if (!success) {
                        break;
                    }

                    int stop = i + k * size - 1;
                    string next = to_string(k) + "["s + dp[i][j] + "]"s;
                    if (dp[i][stop].empty() || dp[i][stop].size() > next.size()) {
                        dp[i][stop] = move(next);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};

TEST(&Solution::encode)