/*
 * @Author: sanjusss
 * @Date: 2021-09-12 10:37:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-12 10:57:48
 * @FilePath: \C\C200\C250\C258\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int end = 1 << n;
        int all = end - 1;
        vector<int> dp(end);
        vector<int> bits;
        vector<vector<int>> lens(n, vector<int>(n));
        for (int mask = 1; mask < end; ++mask) {
            bits.clear();
            for (int i = 0; i < n; ++i) {
                if ((1 << i) & mask) {
                    bits.push_back(i);
                }
            }

            int m = bits.size();
            for (int i = m - 1; i >= 0; --i) {
                lens[i][i] = 1;
                for (int j = i + 1; j < m; ++j) {
                    lens[i][j] = max(lens[i][j - 1], lens[i + 1][j]);
                    if (s[bits[i]] == s[bits[j]]) {
                        lens[i][j] = max(lens[i][j], lens[i + 1][j - 1] + 2);
                    }
                }
            }

            dp[mask] = lens[0][m - 1];
        }

        int ans = 0;
        for (int mask = 1; mask < end; ++mask) {
            ans = max(ans, dp[mask] * dp[all ^ mask]);
        }

        return ans;
    }
};