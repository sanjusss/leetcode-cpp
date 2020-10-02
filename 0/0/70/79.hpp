#pragma once
#include "leetcode.h"

//Ô­Ê¼°æ
//class Solution 
//{
//public:
//    bool exist(vector<vector<char>>& board, string word) 
//    {
//        if (word.size() == 0)
//        {
//            return true;
//        }
//
//        int m = board.size();
//        if (m == 0)
//        {
//            return false;
//        }
//
//        int n = board[0].size();
//        if (n == 0)
//        {
//            return false;
//        }
//
//        vector<vector<int>> passed(m, vector<int>(n, 0));
//        for (int i = 0; i < m; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                if (find(board, word, m, n, i, j, 0, passed))
//                {
//                    return true;
//                }
//            }
//        }
//
//        return false;
//    }
//
//private:
//    bool find(const vector<vector<char>>& board, const string& word, int m, int n, int x, int y, int index, vector<vector<int>>& passed)
//    {
//        static vector<pair<int, int>> directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//
//        if (board[x][y] != word[index])
//        {
//            return false;
//        }
//
//        ++index;
//        if (index == word.size())
//        {
//            return true;
//        }
//
//        passed[x][y] = 1;
//        for (auto& dir : directions)
//        {
//            int nextX = x + dir.first;
//            int nextY = y + dir.second;
//            if (nextX >= 0 && nextX < m &&
//                nextY >= 0 && nextY < n &&
//                passed[nextX][nextY] == 0 &&
//                find(board, word, m, n, nextX, nextY, index, passed))
//            {
//                return true;
//            }
//        }
//
//        passed[x][y] = 0;
//        return false;
//    }
//};


//¸´ÓÃboard
class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }

        int m = board.size();
        if (m == 0)
        {
            return false;
        }

        int n = board[0].size();
        if (n == 0)
        {
            return false;
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (find(board, word, m, n, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool find(vector<vector<char>>& board, const string& word, int m, int n, int x, int y, int index)
    {
        static vector<pair<int, int>> directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

        if (board[x][y] != word[index])
        {
            return false;
        }

        if (index + 1== word.size())
        {
            return true;
        }

        board[x][y] = 0;
        for (auto& dir : directions)
        {
            int nextX = x + dir.first;
            int nextY = y + dir.second;
            if (nextX >= 0 && nextX < m &&
                nextY >= 0 && nextY < n &&
                find(board, word, m, n, nextX, nextY, index + 1))
            {
                return true;
            }
        }

        board[x][y] = word[index];
        return false;
    }
};