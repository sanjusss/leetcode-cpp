#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
    {
        vector<vector<int>> m(2, vector<int>(colsum.size(), 0));
        for (int i = 0; i < colsum.size(); ++i)
        {
            if (colsum[i] == 2)
            {
                --upper;
                --lower;
                colsum[i] = 0;
                m[0][i] = 1;
                m[1][i] = 1;
            }
        }

        for (int i = 0; i < colsum.size(); ++i)
        {
            if (colsum[i] > 0 && upper > 0)
            {
                --upper;
                --colsum[i];
                m[0][i] = 1;
            }

            if (colsum[i] > 0 && lower > 0)
            {
                --lower;
                --colsum[i];
                m[1][i] = 1;
            }

            if (colsum[i] > 0)
            {
                return vector<vector<int>>();
            }
        }

        if (upper != 0 || lower != 0)
        {
            return vector<vector<int>>();
        }
        else
        {
            return m;
        }
    }
};