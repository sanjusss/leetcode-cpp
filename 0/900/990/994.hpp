#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        if (m == 0)
        {
            return 0;
        }

        int n = grid[0].size();
        if (n == 0)
        {
            return 0;
        }

        vector<pair<int, int>> q;
        int remains = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                switch (grid[i][j])
                {
                case 1:
                    ++remains;
                    break;

                case 2:
                    q.push_back({ i, j });
                    break;

                default:
                    break;
                } 
            }
        }

        int ans = 0;
        vector<pair<int, int>> dirs =
        {
            { -1, 0 },
            { 1, 0 },
            { 0, -1 },
            { 0, 1 }
        };
        while (q.empty() == false && remains > 0)
        {
            vector<pair<int, int>> nexts;
            for (auto& p : q)
            {
                for (auto& d : dirs)
                {
                    int i = p.first + d.first;
                    int j = p.second + d.second;
                    if (i < 0 || i >= m ||
                        j < 0 || j >= n ||
                        grid[i][j] != 1)
                    {
                        continue;
                    }

                    grid[i][j] = 2;
                    --remains;
                    nexts.push_back({ i, j });
                }
            }

            q = move(nexts);
            ++ans;
        }

        if (remains > 0)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};