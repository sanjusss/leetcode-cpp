#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        static const vector<vector<int>> dirs =
        {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 }
        };
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (board[i][j] != 'R')
                {
                    continue;
                }

                int ans = 0;
                for (auto& dir : dirs)
                {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    while (x >= 0 && x < 8 && y >= 0 && y < 8)
                    {
                        if (board[x][y] == 'p')
                        {
                            ++ans;
                            break;
                        }
                        else if (board[x][y] == 'B')
                        {
                            break;
                        }

                        x += dir[0];
                        y += dir[1];
                    }
                }

                return ans;
            }
        }

        return 0;
    }
};