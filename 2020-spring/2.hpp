#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int numWays(int n, vector<vector<int>>& relation, int k)
    {
        vector<unordered_set<int>> rs(n);
        for (auto& r : relation)
        {
            rs[r[0]].insert(r[1]);
        }

        vector<int> q;
        q.push_back(0);
        for (int i = 0; i < k; ++i)
        {
            vector<int> next;
            for (int j : q)
            {
                for (int l : rs[j])
                {
                    next.push_back(l);
                }
            }

            q = move(next);
        }

        return count_if(q.begin(), q.end(), [n](int i)
            {
                return i == n - 1;
            });
    }
};