#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int earliestAcq(vector<vector<int>>& logs, int N) 
    {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        vector<set<int>> rs;
        for (const vector<int>& line : logs)
        {
            int a = line[1];
            int b = line[2];
            set<int> newr;
            newr.insert(a);
            newr.insert(b);
            for (auto i = rs.begin(); i != rs.end();)
            {
                auto r = *i;
                if (r.find(a) != r.end() || r.find(b) != r.end())
                {
                    for (auto j : r)
                    {
                        newr.insert(j);
                    }

                    i = rs.erase(i);
                }
                else
                {
                    ++i;
                }
            }

            if (newr.size() == N)
            {
                return line[0];
            }

            rs.push_back(newr);
        }

        return -1;
    }
};