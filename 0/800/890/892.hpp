#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int surfaceArea(vector<vector<int>>& grid) 
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
//            { 0, 1 },
//            { 0, -1 },
//            { 1, 0 },
//            { -1, 0 }
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
//                ans += 2 + grid[i][j] * 4;
//                for (auto& dir : dirs)
//                {
//                    int x = i + dir[0];
//                    int y = j + dir[1];
//                    if (x < 0 || x >= m ||
//                        y < 0 || y >= n)
//                    {
//                        continue;
//                    }
//
//                    if (grid[i][j] >= grid[x][y])
//                    {
//                        ans -= grid[x][y];
//                    }
//                    else
//                    {
//                        ans -= grid[i][j];
//                    }
//                }
//            }
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    int surfaceArea(vector<vector<int>>& grid)
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

                ans += 2 + grid[i][j] * 4;
                if (i > 0)
                {
                    ans -= min(grid[i - 1][j], grid[i][j]) * 2;
                }

                if (j > 0)
                {
                    ans -= min(grid[i][j - 1], grid[i][j]) * 2;
                }
            }
        }

        return ans;
    }
};