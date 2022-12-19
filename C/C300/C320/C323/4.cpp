/*
 * @Author: sanjusss
 * @Date: 2022-12-11 10:19:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-11 11:16:36
 * @FilePath: \C\C300\C320\C323\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> que;
        que.emplace(grid[0][0], 0, 0);
        grid[0][0] = 0;

        int k = queries.size();
        vector<int> is(k);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&queries] (int a, int b) {
            return queries[a] < queries[b];
        });
        vector<int> ans(k);
        int len = 0;
        for (int qi : is) {
            int query = queries[qi];
            while (!que.empty() && query > get<0>(que.top())) {
                ++len;
                auto [_, i, j] = que.top();
                que.pop();
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                        continue;
                    }

                    que.emplace(grid[x][y], x, y);
                    grid[x][y] = 0;
                }
            }

            ans[qi] = len;
        }

        return ans;
    }
};