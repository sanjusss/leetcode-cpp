#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    //动态规划方法，难以理解，时间也没减少多少。
//    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
//    {
//        int xLength = matrix.size();
//        if (xLength == 0)
//        {
//            return matrix;
//        }
//
//        int yLength = matrix[0].size();
//        if (yLength == 0)
//        {
//            return matrix;
//        }
//
//        int def = numeric_limits<int>::max() - 1;
//        for (int i = 0; i < xLength; ++i)
//        {
//            for (int j = 0; j < yLength; ++j)
//            {
//                if (matrix[i][j] == 0)
//                {
//                    continue;
//                }
//
//                matrix[i][j] = def;
//                if (i > 0)
//                {
//                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + 1);
//                }
//
//                if (j > 0)
//                {
//                    matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
//                }
//            }
//        }
//
//        for (int i = xLength - 1; i >= 0; --i)
//        {
//            for (int j = yLength - 1; j >= 0; --j)
//            {
//                if (i != xLength - 1)
//                {
//                    matrix[i][j] = min(matrix[i][j], matrix[i + 1][j] + 1);
//                }
//
//                if (j != yLength - 1)
//                {
//                    matrix[i][j] = min(matrix[i][j], matrix[i][j + 1] + 1);
//                }
//            }
//        }
//
//        return matrix;
//    }
//
//    //bfs
//    //vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
//    //{
//    //    int xLength = matrix.size();
//    //    if (xLength == 0)
//    //    {
//    //        return matrix;
//    //    }
//
//    //    int yLength = matrix[0].size();
//    //    if (yLength == 0)
//    //    {
//    //        return matrix;
//    //    }
//
//    //    queue<pair<int, int>> q;
//    //    for (int x = 0; x < xLength; ++x)
//    //    {
//    //        for (int y = 0; y < yLength; ++y)
//    //        {
//    //            if (matrix[x][y] == 0)
//    //            {
//    //                q.push({ x, y });
//    //            }
//    //            else
//    //            {
//    //                matrix[x][y] = INT_MAX;
//    //            }
//    //        }
//    //    }
//
//    //    int n = 0;
//    //    do
//    //    {
//    //        int length = q.size();
//    //        for (int i = 0; i < length; ++i)
//    //        {
//    //            auto p = q.front();
//    //            q.pop();
//    //            int x = p.first;
//    //            int y = p.second;
//    //            if (matrix[x][y] < n)
//    //            {
//    //                continue;
//    //            }
//
//    //            matrix[x][y] = n;
//
//    //            if (x > 0 && matrix[x - 1][y] > n)
//    //            {
//    //                q.push({ x - 1, y });
//    //            }
//
//    //            if (x + 1 < xLength && matrix[x + 1][y] > n)
//    //            {
//    //                q.push({ x + 1, y });
//    //            }
//
//    //            if (y > 0 && matrix[x][y - 1] > n)
//    //            {
//    //                q.push({ x, y - 1 });
//    //            }
//
//    //            if (y + 1 < yLength && matrix[x][y + 1] > n)
//    //            {
//    //                q.push({ x, y + 1});
//    //            }
//    //        }
//
//    //        ++n;
//    //    } while (q.empty() == false);
//
//    //    return matrix;
//    //}
//};

class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        if (m == 0)
        {
            return matrix;
        }

        int n = matrix[0].size();
        if (n == 0)
        {
            return matrix;
        }

        vector<vector<int>> ans(m, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    ans[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i > 0)
                {
                    ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
                }

                if (j > 0)
                {
                    ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
                }
            }
        }

        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (i < m - 1)
                {
                    ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
                }

                if (j < n - 1)
                {
                    ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
                }
            }
        }

        return ans;
    }
};