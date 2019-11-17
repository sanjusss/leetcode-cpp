#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size();
        int m = grid[0].size();
        k %= n * m;
        if (k == 0)
        {
            return grid;
        }

        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int ti = i;
                int tj = j + k;
                if (tj >= m)
                {
                    ti += tj / m;
                    if (ti >= n)
                    {
                        ti %= n;
                    }

                    tj %= m;
                }
                
                res[ti][tj] = grid[i][j];
            }
        }

        return res;
    }
};