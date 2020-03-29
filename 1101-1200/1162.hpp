#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        if (m == 0)
        {
            return -1;
        }

        int n = grid[0].size();
        if (n == 0)
        {
            return -1;
        }

        vector<pair<int, int>> q;
        int count0 = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    q.push_back({ i, j });
                }
                else
                {
                    ++count0;
                }
            }
        }

        if (count0 == 0)
        {
            return -1;
        }

        int ans = -1;
        vector<pair<int, int>> dirs =
        {
            { 0, 1 },
            { 0, -1 },
            { 1, 0 },
            { -1, 0 }
        };
        while (q.empty() == false)
        {
            ++ans;
            vector<pair<int, int>> next;
            for (auto& p : q)
            {
                for (auto& dir : dirs)
                {
                    int x = p.first + dir.first;
                    int y = p.second + dir.second;
                    if (x < 0 || x >= m ||
                        y < 0 || y >= n ||
                        grid[x][y] != 0)
                    {
                        continue;
                    }

                    grid[x][y] = 1;
                    next.push_back({ x, y });
                }
            }

            q = move(next);
        }

        return ans;
    }
};