#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int closedIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int x = 1; x < m - 1; ++x)
        {
            for (int y = 1; y < n - 1; ++y)
            {
                if (grid[x][y] == 0 &&
                    isNewClosedIsland(m, n, grid, x, y))
                {
                    ++count;
                }
            }
        }

        return count;
    }

    bool isNewClosedIsland(int m, int n, vector<vector<int>>& grid, int x, int y)
    {
        if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
        {
            return false;
        }

        grid[x][y] = 1;
        bool failed = false;

        if (grid[x - 1][y] == 0 &&
            isNewClosedIsland(m, n, grid, x - 1, y) == false)
        {
            failed = true;
        }

        if (grid[x + 1][y] == 0 &&
            isNewClosedIsland(m, n, grid, x + 1, y) == false)
        {
            failed = true;
        }

        if (grid[x][y - 1] == 0 &&
            isNewClosedIsland(m, n, grid, x, y - 1) == false)
        {
            failed = true;
        }

        if (grid[x][y + 1] == 0 &&
            isNewClosedIsland(m, n, grid, x, y + 1) == false)
        {
            failed = true;
        }

        return failed == false;
    }
};