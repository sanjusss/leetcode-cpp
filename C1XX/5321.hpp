#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>> d(n, vector<int>(n, INT_MAX >> 1));
        for (auto& edge : edges)
        {
            d[edge[0]][edge[1]] = edge[2];
            d[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i == k || j == k || i == j)
                    {
                        continue;
                    }

                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        int value = INT_MAX;
        int index = -1;
        for (int i = n - 1; i >= 0; --i)
        {
            int c = count_if(d[i].begin(), d[i].end(), [distanceThreshold](int a) { return a <= distanceThreshold; });
            if (c < value)
            {
                value = c;
                index = i;
            }
        }

        return index;
    }
};