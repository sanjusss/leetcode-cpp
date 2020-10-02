#pragma once
#include "leetcode.h"

class SubrectangleQueries 
{
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) :
        m_rectangle(rectangle)
    {

    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) 
    {
        for (int i = row1; i <= row2; ++i)
        {
            fill(m_rectangle[i].begin() + col1, m_rectangle[i].begin() + col2 + 1, newValue);
        }
    }

    int getValue(int row, int col) 
    {
        return m_rectangle[row][col];
    }

private:
    vector<vector<int>> m_rectangle;
};