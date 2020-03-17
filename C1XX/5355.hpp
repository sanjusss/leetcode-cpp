#pragma once
#include "leetcode.h"

class Solution 
{
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        vector<vector<int>> conn(n + 1);
        for (auto& e : edges)
        {
            conn[e[0]].push_back(e[1]);
            conn[e[1]].push_back(e[0]);
        }

        vector<int> parents(n + 1); 
        vector<vector<int>> children(n + 1);
        queue<int> q;
        q.push(1);
        vector<bool> used(n + 1);
        while (q.empty() == false)
        {
            int i = q.front();
            q.pop();
            if (used[i])
            {
                continue;
            }

            used[i] = true;
            for (int j : conn[i])
            {
                if (used[j])
                {
                    continue;
                }

                parents[j] = i;
                children[i].push_back(j);
                q.push(j);
            }
        }

        int level = 0;
        int i = target;
        double ans = 1;
        while (parents[i] != 0)
        {
            i = parents[i];
            ++level;
            ans /= children[i].size();
        }

        if (level > t ||
            (level < t && children[target].empty() == false))
        {
            return 0;
        }
        else
        {
            return ans;
        }
    }
};