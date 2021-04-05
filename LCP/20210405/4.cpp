/*
 * @Author: sanjusss
 * @Date: 2021-04-05 15:48:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-05 16:36:47
 * @FilePath: \LCP\20210405\4.cpp
 */
#include "leetcode.h"

class Solution {
    typedef tuple<int, int, int, int, int, int> state;

public:
    bool escapeMaze(vector<vector<string>>& maze) {
        static const vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

        int m = maze[0].size();
        int n = maze[0][0].size();
        if (m == 1 && n == 1) {
            return true;
        }

        queue<state> q;
        q.emplace(0, 0, 0, 0, 0, 0);
        int mazeSize = maze.size();
        for (int k = 1; k < mazeSize && !q.empty(); ++k) {
            auto& curMap = maze[k];
            int remainStep = mazeSize - k;
            for (int s = q.size(); s > 0; --s) {
                //当前位置
                int i;
                int j;
                //已用临时消除
                int ti;
                int tj;
                //已用永久消除
                int pi;
                int pj;
                tie(i, j, ti, tj, pi, pj) = q.front();
                q.pop();
                for (auto& [di, dj] : dirs) {
                    //下一轮坐标
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || ni + nj + remainStep < m + n - 2) {
                        continue;
                    }

                    if (ni == m - 1 && nj == n - 1) {
                        return true;
                    }

                    if (curMap[ni][nj] == '#') {
                        if (ti == 0 && tj == 0) {
                            q.emplace(ni, nj, ni, nj, pi, pj);
                        }

                        if ((pi == 0 && pj == 0) || (pi == ni && pj == nj)) {
                            q.emplace(ni, nj, ti, tj, ni, nj);
                        }
                    }
                    else {
                        q.emplace(ni, nj, ti, tj, pi, pj);
                    }
                }
            }
        }

        while (!q.empty()) {
            //当前位置
            int i;
            int j;
            //已用临时消除
            int ti;
            int tj;
            //已用永久消除
            int pi;
            int pj;
            tie(i, j, ti, tj, pi, pj) = q.front();
            q.pop();
            if ((i == m - 2 && j == n - 1) || (i == m - 1 && j == n - 2)) {
                return true;
            } 
        }

        return false;
    }
};

TEST(&Solution::escapeMaze)