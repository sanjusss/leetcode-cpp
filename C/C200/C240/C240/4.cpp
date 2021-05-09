/*
 * @Author: sanjusss
 * @Date: 2021-05-09 11:15:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-09 21:08:51
 * @FilePath: \C\C200\C240\C240\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> conn(n);
        vector<int> inDegree(n);
        for (auto& e : edges) {
            conn[e[0]].push_back(e[1]);
            ++inDegree[e[1]];
        }

        vector<vector<int>> dp(n, vector<int>(26));
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int ans = 0;
        while (!q.empty()) {
            ++cnt;
            int i = q.front();
            q.pop();

            ans = max(ans, ++dp[i][colors[i] - 'a']);
            for (int j : conn[i]) {
                if (--inDegree[j] == 0) {
                    q.push(j);
                }

                for (int k = 0; k < 26; ++k) {
                    dp[j][k] = max(dp[j][k], dp[i][k]);
                }
            }
        }

        return cnt == n ? ans : -1;
    }
};