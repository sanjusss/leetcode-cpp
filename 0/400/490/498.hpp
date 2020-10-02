#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        int rLength = matrix.size();
        if (rLength == 0)
        {
            return res;
        }

        int cLength = matrix[0].size();
        int length = rLength + cLength - 1;
        int start;
        int end;
        for (int i = 0; i < length; ++i)
        {
            if (i % 2 == 0)
            {
                start = min(rLength - 1, i);
                end = max(i - cLength + 1, 0);
                for (int j = start; j >= end; --j)
                {
                    res.push_back(matrix[j][i - j]);
                }
            }
            else
            {
                start = min(cLength - 1, i);
                end = max(i - rLength + 1, 0);
                for (int j = start; j >= end; --j)
                {
                    res.push_back(matrix[i - j][j]);
                }
            }
        }

        return res;
    }
};