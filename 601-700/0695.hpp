#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int maxAreaOfIsland(vector<vector<int>>& grid)
//    {
//        int m = grid.size();
//        if (m == 0)
//        {
//            return 0;
//        }
//
//        int n = grid[0].size();
//        if (n == 0)
//        {
//            return 0;
//        }
//
//        int ans = 0;
//        static const vector<vector<int>> dirs = 
//        {
//            { 1, 0 },
//            { -1, 0 },
//            { 0, 1 },
//            { 0,-1 },
//        };
//        for (int i = 0; i < m; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                if (grid[i][j] == 0)
//                {
//                    continue;
//                }
//
//                int count1 = 0;
//                queue<pair<int, int>> q;
//                q.push({ i, j });
//                while (q.empty() == false)
//                {
//                    auto p = q.front();
//                    q.pop();
//                    if (p.first < 0 || p.first >= m ||
//                        p.second < 0 || p.second >= n ||
//                        grid[p.first][p.second] == 0)
//                    {
//                        continue;
//                    }
//
//                    grid[p.first][p.second] = 0;
//                    ++count1;
//                    for (auto& dir : dirs)
//                    {
//                        q.push({ p.first + dir[0], p.second + dir[1] });
//                    }
//                }
//
//                ans = max(ans, count1);
//            }
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
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

        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }

                int count1 = 0;
                dfs(grid, m, n, i, j, count1);
                ans = max(ans, count1);
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int& count1)
    {
        static const vector<vector<int>> dirs =
        {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0,-1 },
        };

        if (i < 0 || i >= m ||
            j < 0 || j >= n ||
            grid[i][j] == 0)
        {
            return;
        }

        grid[i][j] = 0;
        ++count1;
        for (auto& dir : dirs)
        {
            dfs(grid, m, n, i + dir[0], j + dir[1], count1);
        }
    }
};