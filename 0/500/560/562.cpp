/*
 * @Author: sanjusss
 * @Date: 2023-02-24 08:41:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-24 09:27:26
 * @FilePath: \0\500\560\562.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<vector<int>>> cnt(m, vector<vector<int>>(n, vector<int>(4)));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    continue;
                }

                // 0
                cnt[i][j][0] = i > 0 ? cnt[i - 1][j][0] + 1 : 1;
                ans = max(ans, cnt[i][j][0]);

                // 1
                cnt[i][j][1] = j > 0 ? cnt[i][j - 1][1] + 1 : 1;
                ans = max(ans, cnt[i][j][1]);

                // 2
                cnt[i][j][2] = j > 0 && i > 0 ? cnt[i - 1][j - 1][2] + 1 : 1;
                ans = max(ans, cnt[i][j][2]);

                // 3
                cnt[i][j][3] = i > 0 && j + 1 < n ? cnt[i - 1][j + 1][3] + 1 : 1;
                ans = max(ans, cnt[i][j][3]);
            }
        }

        return ans;
    }
};

TEST(&Solution::longestLine)