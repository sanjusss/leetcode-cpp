#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int countSquares(vector<vector<int>>& matrix) 
//    {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        int count = 0;
//        for (int length = min(m, n); length >= 1; --length)
//        {
//            for (int i = 0; i <= m - length; ++i)
//            {
//                for (int j = 0; j <= n - length; ++j)
//                {
//                    if (isSquare(i, j, length, matrix))
//                    {
//                        ++count;
//                    }
//                }
//            }
//        }
//
//        return count;
//    }
//
//    bool isSquare(int x, int y, int length, vector<vector<int>>& matrix)
//    {
//        for (int i = x + length - 1; i >= x; --i)
//        {
//            for (int j = y + length - 1; j >= y; --j)
//            {
//                if (matrix[i][j] == 0)
//                {
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }
//};


class Solution
{
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                sum[i + 1][j + 1] = matrix[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
            }
        }

        int count = 0;
        for (int length = min(m, n); length >= 1; --length)
        {
            for (int i = 0; i <= m - length; ++i)
            {
                for (int j = 0; j <= n - length; ++j)
                {
                    if (length * length ==
                        (sum[i][j] + sum[i + length][j + length] - sum[i][j + length] - sum[i + length][j]))
                    {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};