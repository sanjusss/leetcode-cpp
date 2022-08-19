/*
 * @Author: sanjusss
 * @Date: 2022-08-19 08:48:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-19 08:58:47
 * @FilePath: \0\500\500\505.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        int bi = start[0];
        int bj = start[1];
        int ei = destination[0];
        int ej = destination[1];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(0, bi, bj);
        dis[bi][bj] = 0;
        while (!q.empty()) {
            auto [d, i, j] = q.top();
            q.pop();
            if (i == ei && j == ej) {
                return d;
            }

            for (auto [dx, dy] : dirs) {
                int x = i;
                int y = j;
                int nx = x + dx;
                int ny = y + dy;
                int nd = d;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 0) {
                    ++nd;
                    x = nx;
                    y = ny;
                    nx += dx;
                    ny += dy;
                }

                if (nd < dis[x][y]) {
                    dis[x][y] = nd;
                    q.emplace(nd, x, y);
                }
            }
        }

        return -1;
    }
};