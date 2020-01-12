#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if (connections.size() < n - 1)
        {
            return -1;
        }

        vector<int> networks(n, 0);
        for (auto& conn : connections)
        {
            int start = conn[0];
            int end = conn[1];
            int starti = networks[start];
            int endi = networks[end];
            if (starti == 0 && endi == 0)
            {
                networks[start] = start + 1;
                networks[end] = start + 1;
            }
            else if (starti == endi)
            {
                continue;
            }
            else if (starti == 0)
            {
                networks[start] = endi;
            }
            else if (endi == 0)
            {
                networks[end] = starti;
            }
            else
            {
                for (int i = 0; i < n; ++i)
                {
                    if (networks[i] == endi)
                    {
                        networks[i] = starti;
                    }
                }
            }
        }

        int networksCount = 0;
        unordered_set<int> networksSet;
        for (int i : networks)
        {
            if (i == 0)
            {
                ++networksCount;
            }
            else
            {
                networksSet.insert(i);
            }
        }

        return networksCount + networksSet.size() - 1;
    }
};