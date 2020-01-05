#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int maximalRectangle(vector<vector<char>>& matrix) 
//    {
//        int m = matrix.size();
//        if (m == 0)
//        {
//            return 0;
//        }
//
//        int n = matrix[0].size();
//        if (n == 0)
//        {
//            return 0;
//        }
//
//        //dp[i + 1][j + 1]表示在矩阵[(0,0),(i,j)]中的最大矩形面积。
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//        vector<vector<vector<pair<int, int>>>> rects(m + 1, vector<vector<pair<int, int>>>(n + 1));
//        for (int i = 1; i <= m; ++i)
//        {
//            for (int j = 1; j <= n; ++j)
//            {
//                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//                if (matrix[i - 1][j - 1] == '1')
//                {
//                    //寻找终点为(i - 1, j - 1)的最大矩形。
//                    int area = 1;
//                    for (auto& pos : rects[i - 1][j])
//                    {
//                        int starti = pos.first;
//                        int startj = j;
//                        for (int k = j - 1; k >= pos.second; --k)
//                        {
//                            if (matrix[i - 1][k - 1] == '1')
//                            {
//                                startj = k;
//                            }
//                            else
//                            {
//                                break;
//                            }
//                        }
//
//                        area = max(area, (i - starti + 1) * (j - startj + 1));
//                        rects[i][j].push_back({ starti, startj });
//                    }
//
//                    for (auto& pos : rects[i][j - 1])
//                    {
//                        int starti = i;
//                        int startj = pos.second;
//                        for (int k = i - 1; k >= pos.first; --k)
//                        {
//                            if (matrix[k - 1][j - 1] == '1')
//                            {
//                                starti = k;
//                            }
//                            else
//                            {
//                                break;
//                            }
//                        }
//
//                        area = max(area, (i - starti + 1) * (j - startj + 1));
//                        rects[i][j].push_back({ starti, startj });
//                    }
//                    
//                    if (rects[i][j].empty())
//                    {
//                        rects[i][j].push_back({ i, j });
//                    }
//
//                    dp[i][j] = max(dp[i][j], area);
//                }
//            }
//        }
//
//        return dp[m][n];
//    }
//};

class Solution 
{
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }

        int n = matrix[0].size();
        if (n == 0)
        {
            return 0;
        }
        
        vector<int> heights(n, 0);
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                heights[j] = (matrix[i][j] == '1') ? (heights[j] + 1) : 0;
            }

            res = max(res, maximalRectangle(heights));
        }

        return res;
    }

private:
    int maximalRectangle(vector<int> heights)
    {
        stack<int> unhandles;
        unhandles.push(0);
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        int res = 0;
        for (int i = 1; i < heights.size(); ++i)
        {
            while (heights[unhandles.top()] > heights[i])
            {
                int height = heights[unhandles.top()];
                unhandles.pop();
                res = max(res, height * (i - unhandles.top() - 1));
            }

            unhandles.push(i);
        }

        return res;
    }
};