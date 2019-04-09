#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> rows;
        if (numRows <= 0)
        {
            return rows;
        }

        rows.push_back({ 1 });
        for (int i = 1; i < numRows; ++i)
        {
            vector<int> row(i + 1, 1);
            int mid = i / 2;
            for (int j = 1; j <= mid; ++j)
            {
                row[j] = rows[i - 1][j - 1] + rows[i - 1][j];
                row[i - j] = row[j];
            }

            rows.push_back(row);
        }

        return rows;
    }
};