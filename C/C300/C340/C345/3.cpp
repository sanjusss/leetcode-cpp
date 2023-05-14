/*
 * @Author: sanjusss
 * @Date: 2023-05-14 10:27:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-14 10:53:15
 * @FilePath: \C\C300\C340\C345\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<int> q;
        for (int i = 0; i < m; ++i) {
            q.emplace(i);
        }

        int ans = 0;
        vector<bool> nexts(m);
        for (int j = 0; !q.empty(); ++j) {
            fill(nexts.begin(), nexts.end(), false);
            for (int qi = q.size(); qi > 0; --qi) {
                int i = q.front();
                q.pop();
                for (int dx : { -1, 0, 1 }) {
                    int x = i + dx;
                    int y = j + 1;
                    if (x < 0 || x >= m || y < 0 || y >= n || nexts[x] || grid[i][j] >= grid[x][y]) {
                        continue;
                    }

                    nexts[x] = true;
                    q.push(x);
                }
            }

            if (!q.empty()) {
                ++ans;
            }
        }

        return ans;
    }
};