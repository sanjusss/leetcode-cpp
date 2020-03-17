#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        unordered_map<int, vector<int>> nodes;
        for (int i = 0; i < n; ++i)
        {
            nodes[manager[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({ headID, 0 });
        vector<int> time(n, 0);
        int ans = 0;
        while (q.empty() == false)
        {
            auto& p = q.front();
            ans = max(ans, p.second);
            if (nodes.find(p.first) != nodes.end())
            {
                int nextTime = informTime[p.first] + p.second;
                for (auto i : nodes[p.first])
                {
                    q.push({ i, nextTime });
                }
            }

            q.pop();
        }

        return ans;
    }
};