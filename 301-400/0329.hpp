#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int longestIncreasingPath(vector<vector<int>>& matrix) 
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
//        int dirs[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
//        int longest = 0;
//        while (true)
//        {
//            bool canWalk = false;
//            vector<vector<int>> tops;
//            for (int i = 0; i < m; ++i)
//            {
//                for (int j = 0; j < n; ++j)
//                {
//                    if (matrix[i][j] == INT_MIN)
//                    {
//                        continue;
//                    }
//
//                    canWalk = true;
//                    bool isTop = true;
//                    for (auto& k : dirs)
//                    {
//                        int x = i + k[0];
//                        int y = j + k[1];
//                        if (x < 0 || x >= m ||
//                            y < 0 || y >= n ||
//                            matrix[i][j] >= matrix[x][y])
//                        {
//                            continue;
//                        }
//
//                        isTop = false;
//                    }
//
//                    if (isTop)
//                    {
//                        tops.push_back({ i, j });
//                    }
//                }
//            }
//
//            for (auto& i : tops)
//            {
//                matrix[i[0]][i[1]] = INT_MIN;
//            }
//
//            if (canWalk)
//            {
//                ++longest;
//            }
//            else
//            {
//                break;
//            }
//        }
//
//        return longest;
//    }
//};

//当数组大小为2时用pair代替vector，速度更快。
class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
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

        int dirs[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        vector<pair<int, int>> tops;
        vector<vector<int>> conn(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (auto& k : dirs)
                {
                    int x = i + k[0];
                    int y = j + k[1];
                    if (x < 0 || x >= m ||
                        y < 0 || y >= n ||
                        matrix[i][j] >= matrix[x][y])
                    {
                        continue;
                    }

                    ++conn[i][j];
                }

                if (conn[i][j] == 0)
                {
                    tops.push_back({ i, j });
                }
            }
        }

        int longest = 0;
        while (tops.empty() == false)
        {
            vector<pair<int, int>> nextTops;
            for (auto& pos : tops)
            {
                int i = pos.first;
                int j = pos.second;
                for (auto& k : dirs)
                {
                    int x = i + k[0];
                    int y = j + k[1];
                    if (x < 0 || x >= m ||
                        y < 0 || y >= n ||
                        matrix[i][j] <= matrix[x][y])
                    {
                        continue;
                    }

                    --conn[x][y];
                    if (conn[x][y] == 0)
                    {
                        nextTops.push_back({ x, y });
                    }
                }
            }

            ++longest;
            tops.swap(nextTops);
        }

        return longest;
    }
};