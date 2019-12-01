#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string tictactoe(vector<vector<int>>& moves) 
    {
        vector<vector<int>> chess(3, vector<int>(3, 0));
        for (int i = 0; i < moves.size(); ++i)
        {
            chess[moves[i][0]][moves[i][1]] = (i % 2 == 0) ? 1 : 2;
        }

        for (int i = 0; i < 3; ++i)
        {
            if (chess[i][0] == chess[i][1] &&
                chess[i][1] == chess[i][2] &&
                chess[i][2] != 0)
            {
                if (chess[i][0] == 1)
                {
                    return "A";
                }
                else
                {
                    return "B";
                }
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            if (chess[0][i] == chess[1][i] &&
                chess[1][i] == chess[2][i] &&
                chess[2][i] != 0)
            {
                if (chess[0][i] == 1)
                {
                    return "A";
                }
                else
                {
                    return "B";
                }
            }
        }

        if (chess[0][0] == chess[1][1] &&
            chess[1][1] == chess[2][2] &&
            chess[2][2] != 0)
        {
            if (chess[0][0] == 1)
            {
                return "A";
            }
            else
            {
                return "B";
            }
        }

        if (chess[0][2] == chess[1][1] &&
            chess[1][1] == chess[2][0] &&
            chess[2][0] != 0)
        {
            if (chess[0][2] == 1)
            {
                return "A";
            }
            else
            {
                return "B";
            }
        }

        if (moves.size() == 9)
        {
            return "Draw";
        }
        else
        {
            return "Pending";
        }
    }
};