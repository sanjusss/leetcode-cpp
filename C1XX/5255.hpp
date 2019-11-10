#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) 
    {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (auto i : indices)
        {
            int ri = i[0];
            for (int c = 0; c < m; ++c)
            {
                ++matrix[ri][c];
            }

            int ci = i[1];
            for (int r = 0; r < n; ++r)
            {
                ++matrix[r][ci];
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] % 2 == 1)
                {
                    ++res;
                }
            }
        }

        return res;
    }
};