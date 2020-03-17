#pragma once
#include "leetcode.h"

class Solution 
{
public:
    void solve(vector<vector<char>>& board) 
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

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
            {
                board[i][0] = '#';
                q.push({ i, 0 });
            }

            if (board[i][n - 1] == 'O')
            {
                board[i][n - 1] = '#';
                q.push({ i, n - 1 });
            }
        }

        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
            {
                board[0][j] = '#';
                q.push({ 0, j });
            }

            if (board[m - 1][j] == 'O')
            {
                board[m - 1][j] = '#';
                q.push({ m - 1, j });
            }
        }

        static const vector<pair<int, int>> directions =
        {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 },
        };

        while (q.empty() == false)
        {
            auto p = q.front();
            q.pop();
            for (auto& dir : directions)
            {
                int i = p.first + dir.first;
                int j = p.second + dir.second;
                if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O')
                {
                    board[i][j] = '#';
                    q.push({ i, j });
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};