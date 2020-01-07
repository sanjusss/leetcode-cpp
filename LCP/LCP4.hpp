#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int domino(int n, int m, vector<vector<int>>& broken) 
    {
        unordered_set<int> brokenIndex;
        for (auto& p : broken)
        {
            brokenIndex.insert(p[0] * m + p[1]);
        }

        vector<pair<int, int>> dirs = { { 1, 0 }, { 0, 1}, { -1, 0 }, { 0, -1 } };
        int size = n * m;
        vector<vector<int>> conn(size);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int index = i * m + j;
                if (brokenIndex.find(index) != brokenIndex.end())
                {
                    continue;
                }

                for (auto& p : dirs)
                {
                    int x = i + p.first;
                    int y = j + p.second;
                    int to = x * m + y;
                    if (x >= 0 && x < n &&
                        y >= 0 && y < m &&
                        brokenIndex.find(to) == brokenIndex.end())
                    {
                        conn[index].push_back(to);
                    }
                }
            }
        }

        vector<int> matches(size, -1);
        vector<bool> checks(size, false);
        int ans = 0;
        for (int u = 0; u < size; ++u)
        {
            if (matches[u] == -1)
            {
                fill(checks.begin(), checks.end(), false);
                if (dfs(u, conn, matches, checks))
                {
                    ++ans;
                }
            }
        }

        return ans;
    }

private:
    bool dfs(int u, const vector<vector<int>>& conn, vector<int>& matches, vector<bool>& checks)
    {
        checks[u] = true;
        for (int v : conn[u])
        {
            if (checks[v])
            {
                continue;
            }

            if (matches[v] == -1 || dfs(v, conn, matches, checks))
            {
                matches[v] = u;
                matches[u] = v;
                return true;
            }
        }

        return false;
    }
};