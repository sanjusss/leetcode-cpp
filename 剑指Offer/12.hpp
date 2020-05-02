#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    bool exist(vector<vector<char>>& board, string word) 
//    {
//        if (word.empty())
//        {
//            return true;
//        }
//
//        int m = board.size();
//        int n = board[0].size();
//        vector<vector<bool>> used(m, vector<bool>(n));
//        for (int i = 0; i < m; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                if (board[i][j] != word[0])
//                {
//                    continue;
//                }
//
//                used[i][j] = true;
//                if (dfs(board, word, m, n, used, i, j, 1))
//                {
//                    return true;
//                }
//
//                used[i][j] = false;
//            }
//        }
//
//        return false;
//    }
//
//private:
//    bool dfs(const vector<vector<char>>& board, const string& word, const int m, const int n, vector<vector<bool>>& used, int x, int y, int cur)
//    {
//        const static vector<pair<int, int>> dirs =
//        {
//            { 1, 0 },
//            { -1, 0 },
//            { 0, -1 },
//            { 0, 1 }
//        };
//
//        if (cur == word.size())
//        {
//            return true;
//        }
//
//        for (auto& dir : dirs)
//        {
//            int nx = x + dir.first;
//            int ny = y + dir.second;
//            if (nx < 0 || nx >= m ||
//                ny < 0 || ny >= n ||
//                used[nx][ny] ||
//                word[cur] != board[nx][ny])
//            {
//                continue;
//            }
//
//            used[nx][ny] = true;
//            if (dfs(board, word, m, n, used, nx, ny, cur + 1))
//            {
//                return true;
//            }
//
//            used[nx][ny] = false;
//        }
//
//        return false;
//    }
//};

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if (word.empty())
        {
            return true;
        }

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, m, n, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, const int m, const int n, int x, int y, int cur)
    {
        if (x < 0 || x >= m ||
            y < 0 || y >= n ||
            board[x][y] != word[cur])
        {
            return false;
        }

        int next = cur + 1;
        if (word.size() == next)
        {
            return true;
        }

        const static vector<pair<int, int>> dirs =
        {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };

        char temp = board[x][y];
        board[x][y] = 0;
        for (auto& dir : dirs)
        {
            if (dfs(board, word, m, n, x + dir.first, y + dir.second, next))
            {
                return true;
            }
        }

        board[x][y] = temp;
        return false;
    }
};