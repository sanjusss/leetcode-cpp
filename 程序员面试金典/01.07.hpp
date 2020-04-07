#pragma once
#include "leetcode.h"

class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int temp;
        for (int i = n / 2 - 1; i >= 0; --i)
        {
            for (int j = (n + 1) / 2 - 1; j >= 0; --j)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};