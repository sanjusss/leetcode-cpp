#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
        {
            return image;
        }

        int xLength = image.size();
        if (xLength == 0)
        {
            return image;
        }

        int yLnegth = image[0].size();
        stack<pair<int, int>> s;
        s.push({ sr, sc });
        do
        {
            auto p = s.top();
            s.pop();
            if (p.first < 0 || p.second < 0 || p.first >= xLength || p.second >= yLnegth
                || image[p.first][p.second] != oldColor)
            {
                continue;
            }

            image[p.first][p.second] = newColor;
            s.push({ p.first - 1, p.second });
            s.push({ p.first + 1, p.second });
            s.push({ p.first, p.second - 1 });
            s.push({ p.first, p.second + 1 });
        } while (s.empty() == false);
        return image;
    }
};