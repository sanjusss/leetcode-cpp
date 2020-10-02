#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    void gameOfLife(vector<vector<int>>& board) 
//    {
//        int m = board.size();
//        if (m == 0)
//        {
//            return;
//        }
//
//        int n = board[0].size();
//        if (n == 0)
//        {
//            return;
//        }
//
//        auto ans = vector<vector<int>>(m, vector<int>(n));
//        for (int i = 0; i < m; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                ans[i][j] = isAlive(board, m, n, i, j);
//            }
//        }
//
//        ans.swap(board);
//    }
//
//private:
//    int isAlive(vector<vector<int>>& board, int m, int n, int x, int y)
//    {
//        static const vector<pair<int, int>> directions =
//        {
//            { -1, -1 },
//            { -1, 0 },
//            { -1, 1 },
//            { 0, -1 },
//            { 0, 1 },
//            { 1, -1 },
//            { 1, 0 },
//            { 1, 1 }
//        };
//
//        int nbs = 0;
//        for (auto& dir : directions)
//        {
//            int i = x + dir.first;
//            int j = y + dir.second;
//            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 1)
//            {
//                ++nbs;
//            }
//        }
//
//        if (nbs == 2)
//        {
//            return board[x][y];
//        }
//        else if (nbs == 3)
//        {
//            return 1;
//        }
//        else
//        {
//            return 0;
//        }
//    }
//};

//原地算法的解法很多，共同点是用原有的int同时保存保存初始状态和周围的存货数量。
class Solution
{
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int m = board.size();
        if (m == 0)
        {
            return;
        }

        int n = board[0].size();
        if (n == 0)
        {
            return;
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                test(board, m, n, i, j);
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int nbs = board[i][j] / 2;
                if (nbs == 2)
                {
                    board[i][j] %= 2;
                }
                else if (nbs == 3)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }
    }

private:
    void test(vector<vector<int>>& board, int m, int n, int x, int y)
    {
        static const vector<pair<int, int>> directions =
        {
            { -1, -1 },
            { -1, 0 },
            { -1, 1 },
            { 0, -1 },
            { 0, 1 },
            { 1, -1 },
            { 1, 0 },
            { 1, 1 }
        };

        for (auto& dir : directions)
        {
            int i = x + dir.first;
            int j = y + dir.second;
            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] % 2 == 1)
            {
                board[x][y] += 2;
            }
        }
    }
};