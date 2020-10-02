#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int largest = 0;

        stack<int> unhandles;
        unhandles.push(0);
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 1; i < heights.size(); ++i)
        {
            while (heights[unhandles.top()] > heights[i])
            {
                int height = heights[unhandles.top()];
                unhandles.pop();
                largest = max(largest, height * (i - unhandles.top() - 1));
            }

            unhandles.push(i);
        }

        return largest;
    }
};