#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0)
        {
            return ans;
        }

        int n = matrix[0].size();
        if (n == 0)
        {
            return ans;
        }

        for (int i = 0; i < m; ++i)
        {
            int minIndex = 0;
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][minIndex] > matrix[i][j])
                {
                    minIndex = j;
                }
            }

            bool success = true;
            for (int k = 0; k < m; ++k)
            {
                if (matrix[k][minIndex] > matrix[i][minIndex])
                {
                    success = false;
                    break;
                }
            }

            if (success)
            {
                ans.push_back(matrix[i][minIndex]);
            }
        }

        return ans;
    }
};