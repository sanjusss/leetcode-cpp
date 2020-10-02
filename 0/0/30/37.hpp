#pragma once
#include "leetcode.h"

class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        complete(board, 0, 0);
    }

    vector<bool>& calcUsed(const vector<vector<char>>& sudoku, int x, int y)
    {
        static vector<vector<vector<bool>>> s_remains = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(10, false)));
        vector<bool>& used = s_remains[x][y];
        for (int i = 0; i < 10; ++i)
        {
            used[i] = false;
        }

        for (int i = 0; i < 9; ++i)
        {
            if (sudoku[i][y] == '.')
            {
                continue;
            }

            used[sudoku[i][y] - '0'] = true;
        }

        for (int j = 0; j < 9; ++j)
        {
            if (sudoku[x][j] == '.')
            {
                continue;
            }

            used[sudoku[x][j] - '0'] = true;
        }

        int istart = x - (x % 3);
        int iend = istart + 3;
        int jstart = y - (y % 3);
        int jend = jstart + 3;
        for (int i = istart; i < iend; ++i)
        {
            for (int j = jstart; j < jend; ++j)
            {
                if (sudoku[i][j] == '.')
                {
                    continue;
                }

                used[sudoku[i][j] - '0'] = true;
            }
        }

        return used;
    }

    bool complete(vector<vector<char>>& sudoku, int x, int y)
    {
        if (y == 9)
        {
            y = 0;
            ++x;
            if (x == 9)
            {
                return true;
            }
        }

        for (int i = x; i < 9; ++i)
        {
            for (int j = i > x ? 0 : y; j < 9; ++j)
            {
                if (sudoku[i][j] != '.')
                {
                    continue;
                }

                auto& used = calcUsed(sudoku, i, j);
                for (int k = 1; k <= 9; ++k)
                {
                    if (used[k])
                    {
                        continue;
                    }

                    sudoku[i][j] = k + '0';
                    if (complete(sudoku, i, j + 1))
                    {
                        return true;
                    }
                }

                sudoku[i][j] = '.';
                return false;
            }
        }

        return true;
    }
};
