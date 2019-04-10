#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int nums = 0;
        int xLength = grid.size();
        if (xLength == 0)
        {
            return nums;
        }

        int yLength = grid[0].size();
        for (int x = 0; x < xLength; ++x)
        {
            for (int y = 0; y < yLength; ++y)
            {
                if (grid[x][y] == '1')
                {
                    ++nums;
                    clearLand(x, y, xLength, yLength, grid);
                }
            }
        }

        return nums;
    }

private:
    void  clearLand(int x, int y, int xLength, int yLength, vector<vector<char>>& grid)
    {
        grid[x][y] = '0';

        if (x != 0 && grid[x - 1][y] == '1')
        {
            clearLand(x - 1, y, xLength, yLength, grid);
        }

        if (y != 0 && grid[x][y - 1] == '1')
        {
            clearLand(x, y - 1, xLength, yLength, grid);
        }

        if (x + 1 != xLength && grid[x + 1][y] == '1')
        {
            clearLand(x + 1, y, xLength, yLength, grid);
        }

        if (y + 1 != yLength && grid[x][y + 1] == '1')
        {
            clearLand(x, y + 1, xLength, yLength, grid);
        }
    }
};