/*
 * @Author: sanjusss
 * @Date: 2023-11-09 22:02:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-09 23:26:07
 * @FilePath: \2000\2200\2250\2258.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        static const int always = 1e9;
        static const vector<pair<int, int>> dirs = {
            { -1, 0 },
            { 1, 0 },
            { 0, -1 },
            { 0, 1 }
        };
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> times(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    times[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        for (int k = 1; !q.empty(); ++k) {
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, j] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2 || times[x][y] >= 0) {
                        continue;
                    }

                    times[x][y] = k;
                    q.emplace(x, y);
                }
            }
        }

        q.emplace(0, 0);
        grid[0][0] = 2;
        
        bool finish = false;
        int ans = always;
        for (int k = 0; !q.empty() && !finish; ++k) {
            int cur = 0;
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, j] = q.front();
                q.pop();
                if (i == m - 1 && j == n - 1) {
                    finish = true;
                }
                
                if (times[i][j] >= 0) {
                    if (i == m - 1 && j == n - 1) {
                        cur = max(cur, times[i][j] - k);
                    }
                    else {
                        cur = max(cur, times[i][j] - k - 1);
                    }
                }
                else {
                    cur = always;
                }

                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0) {
                        continue;
                    }

                    if (x == m - 1 && y == n - 1) {
                        if (times[x][y] >= 0 && times[x][y] <= k) {
                            continue;
                        }
                    }
                    else {                        
                        if (times[x][y] >= 0 && times[x][y] <= k + 1) {
                            continue;
                        }
                    }

                    q.emplace(x, y);
                    grid[x][y] = 2;
                }
            }

            ans = min(ans, cur);
        }

        if (finish) {
            return ans;
        }
        else {
            return -1;
        }
    }
};

TEST(&Solution::maximumMinutes)