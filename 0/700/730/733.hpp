#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
//    {
//        int oldColor = image[sr][sc];
//        if (oldColor == newColor)
//        {
//            return image;
//        }
//
//        int xLength = image.size();
//        if (xLength == 0)
//        {
//            return image;
//        }
//
//        int yLnegth = image[0].size();
//        stack<pair<int, int>> s;
//        s.push({ sr, sc });
//        do
//        {
//            auto p = s.top();
//            s.pop();
//            if (p.first < 0 || p.second < 0 || p.first >= xLength || p.second >= yLnegth
//                || image[p.first][p.second] != oldColor)
//            {
//                continue;
//            }
//
//            image[p.first][p.second] = newColor;
//            s.push({ p.first - 1, p.second });
//            s.push({ p.first + 1, p.second });
//            s.push({ p.first, p.second - 1 });
//            s.push({ p.first, p.second + 1 });
//        } while (s.empty() == false);
//        return image;
//    }
//};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        const int oldColor = image[sr][sc];
        if (oldColor == newColor) {
            return image;
        }

        image[sr][sc] = newColor;
        queue<pair<int, int>> q;
        q.push({ sr, sc });
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 }
        };

        do {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int x;
            int y;
            for (auto& dir : dirs) {
                x = i + dir.first;
                y = j + dir.second;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                if (image[x][y] == oldColor) {
                    image[x][y] = newColor;
                    q.push({ x, y });
                }
            }
        } while (!q.empty());

        return image;
    }
};