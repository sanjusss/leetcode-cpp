/*
 * @Author: sanjusss
 * @Date: 2022-08-17 08:26:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-17 09:37:41
 * @FilePath: \0\400\490\490.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        int m = maze.size();
        int n = maze[0].size();
        int di = destination[0];
        int dj = destination[1];
        vector<vector<bool>> passed(m, vector<bool>(n));
        int si = start[0];
        int sj = start[1];
        passed[si][sj] = true;
        stack<pair<int, int>> s;
        s.emplace(si, sj);
        while (!s.empty()) {
            auto [i, j] = s.top();
            s.pop();
            for (auto [dx, dy] : dirs) {
                int x = i;
                int y = j;
                int nx = x + dx;
                int ny = y + dy;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 0) {
                    x = nx;
                    y = ny;
                    nx += dx;
                    ny += dy;
                }

                if (passed[x][y]) {
                    continue;
                }
                else if (x == di && y == dj) {
                    return true;
                }

                passed[x][y] = true;
                s.emplace(x, y);
            }
        }

        return false;
    }
};

TEST(&Solution::hasPath)