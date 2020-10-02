#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> indegrees(numCourses);
        vector<vector<int>> edges(numCourses);
        for (auto& edge : prerequisites)
        {
            ++indegrees[edge[1]];
            edges[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;
        while (q.empty() == false)
        {
            int i = q.front();
            q.pop();
            ans.push_back(i);
            for (auto& j : edges[i])
            {
                if (--indegrees[j] == 0)
                {
                    q.push(j);
                }
            }
        }

        if (ans.size() == numCourses)
        {
            reverse(ans.begin(), ans.end());
            return ans;
        }
        else
        {
            return {};
        }
    }
};