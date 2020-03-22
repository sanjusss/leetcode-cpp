#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool hasValidPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        if (m == 0)
        {
            return false;
        }

        int n = grid[0].size();
        if (n == 0)
        {
            return false;
        }

        vector<vector<bool>> used(m, vector<bool>(n));
        stack<pair<int, int>> s;
        s.push({ 0, 0 });

        static const vector<pair<int, int>> dirs = 
        {
            { 0, -1},//左
            { 0, 1},//右
            { -1, 0},//上
            { 1, 0}//下
        };

        static const vector<unordered_set<int>> dirsValid =
        {
            { 4, 6, 1},//左
            { 3, 5, 1},//右
            { 2, 3, 4},//上
            { 2, 5, 6}//下
        };

        static const vector<vector<int>> gridDirsIndex =
        {
            {},
            { 0, 1 },
            { 2, 3 },
            { 0, 3 },
            { 1, 3 },
            { 0, 2 },
            { 1, 2 },
        };

        while (s.empty() == false)
        {
            auto p = s.top();
            s.pop();
            if (used[p.first][p.second])
            {
                continue;
            }
            else
            {
                used[p.first][p.second] = true;
            }

            if (p.first == m - 1 && p.second == n - 1)
            {
                return true;
            }

            for (int i : gridDirsIndex[grid[p.first][p.second]])
            {
                auto next = make_pair(p.first + dirs[i].first, p.second + dirs[i].second);
                if (next.first < 0 || next.first >= m ||
                    next.second < 0 || next.second >= n ||
                    dirsValid[i].find(grid[next.first][next.second]) == dirsValid[i].end())
                {
                    continue;
                }

                s.push(next);
            }
        }

        return false;
    }
};