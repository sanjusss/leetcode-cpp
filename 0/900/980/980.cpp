/*
 * @Author: sanjusss
 * @Date: 2023-08-04 08:42:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-04 09:10:05
 * @FilePath: \0\900\980\980.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 },
        };
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        int allMask = (1 << total) - 1;
        int end = 0;
        int begin = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -1) {
                    begin |= 1 << ((i * n) + j);
                }
                else if (grid[i][j] == 1) {
                    begin |= 1 << ((i * n) + j);
                    begin |= (i * n + j) << total;
                }
                else if (grid[i][j] == 2) {
                    end |= 1 << ((i * n) + j);
                    end |= (i * n + j) << total;
                }
            }
        }

        unordered_map<int, int> dp;
        dp[begin] = 1;
        queue<int> q;
        q.emplace(begin);
        while (!q.empty()) {
            int mask = q.front();
            q.pop();
            int cur = mask >> total;
            int i = cur / n;
            int j = cur % n;
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                int nxt = x * n + y;
                if (mask & (1 << nxt)) {
                    continue;
                }

                int nxtMask = (allMask & mask) | (1 << nxt);
                nxtMask |= nxt << total;
                if (!dp.count(nxtMask) && (nxtMask & end) != end) {
                    q.emplace(nxtMask);
                }

                dp[nxtMask] += dp[mask];
            }
        }

        int endMask = allMask | end;
        return dp[endMask];
    }
};