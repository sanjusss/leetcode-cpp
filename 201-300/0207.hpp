#pragma once
#include "leetcode.h"

//class Solution
//{
//public:
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
//    {
//        vector<vector<int>> conditions(numCourses);
//        for (auto& i : prerequisites)
//        {
//            conditions[i[0]].push_back(i[1]);
//        }
//
//        vector<bool> visit(numCourses);
//        for (int i = 0; i < numCourses; ++i)
//        {
//            fill(visit.begin(), visit.end(), false);
//            vector<int> q = conditions[i];
//            do
//            {
//                vector<int> next;
//                for (int j : q)
//                {
//                    if (i == j)
//                    {
//                        return false;
//                    }
//
//                    if (visit[j])
//                    {
//                        continue;
//                    }
//
//                    visit[j] = true;
//                    for (int k : conditions[j])
//                    {
//                        next.push_back(k);
//                    }
//                }
//
//                q = move(next);
//            } while (q.empty() == false);
//        }
//
//        return true;
//    }
//};

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> indegrees(numCourses);
        for (auto& i : prerequisites)
        {
            ++indegrees[i[1]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }

        while (q.empty() == false)
        {
            int i = q.front();
            q.pop();
            --numCourses;
            for (auto& line : prerequisites)
            {
                if (line[0] == i)
                {
                    --indegrees[line[1]];
                    if (indegrees[line[1]] == 0)
                    {
                        q.push(line[1]);
                    }
                }
            }
        }

        return numCourses == 0;
    }
};