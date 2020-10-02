#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        int m = matrix.size();
        if (m == 0)
        {
            return res;
        }

        int n = matrix[0].size();
        int length = (min(m, n) + 1) / 2;
        int yMax;
        int xMax;
        for (int i = 0; i < length; ++i)
        {
            yMax = n - i - 1;
            if (i > yMax)
            {
                break;
            }

            for (int y = i; y <= yMax; ++y)
            {
                res.push_back(matrix[i][y]);
            }

            xMax = m - i - 1;
            if (i + 1 > xMax)
            {
                break;
            }

            for (int x = i + 1; x <= xMax; ++x)
            {
                res.push_back(matrix[x][yMax]);
            }

            if (yMax - 1 < i)
            {
                break;
            }

            for (int y = yMax - 1; y >= i; --y)
            {
                res.push_back(matrix[xMax][y]);
            }

            if (xMax - 1 <= i)
            {
                break;
            }

            for (int x = xMax - 1; x > i; --x)
            {
                res.push_back(matrix[x][i]);
            }
        }

        return res;
    }
};