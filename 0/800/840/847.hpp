#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int shortestPathLength(vector<vector<int>>& graph) 
//    {
//        int n = graph.size();
//        uint32_t end = (1 << n) - 1;
//        vector<pair<int, uint32_t>> q(n);
//        for (int i = 0; i < n; ++i)
//        {
//            q[i].first = i;
//        }
//
//        uint32_t cur;
//        for (int ans = 0; ; ++ans)
//        {
//            vector<pair<int, uint32_t>> nexts;
//            for (auto& p : q)
//            {
//                cur = p.second | (1 << p.first);
//                if (cur == end)
//                {
//                    return ans;
//                }
//
//                for (int j : graph[p.first])
//                {
//                    nexts.push_back({ j, cur });
//                }
//            }
//
//            q = move(nexts);
//        }
//
//        return -1;
//    }
//};

//class Solution
//{
//public:
//    int shortestPathLength(vector<vector<int>>& graph)
//    {
//        int n = graph.size();
//        int end = (1 << n) - 1;
//        vector<pair<int, int>> q(n);
//        for (int i = 0; i < n; ++i)
//        {
//            q[i].first = i;
//        }
//
//        vector<vector<bool>> passed(n, vector<bool>(1 << n));
//
//        int cur;
//        for (int ans = 0; ; ++ans)
//        {
//            vector<pair<int, int>> nexts;
//            for (auto& p : q)
//            {
//                cur = p.second | (1 << p.first);
//                if (cur == end)
//                {
//                    return ans;
//                }
//
//                if (passed[p.first][cur])
//                {
//                    continue;
//                }
//                else
//                {
//                    passed[p.first][cur] = true;
//                }
//
//                for (int j : graph[p.first])
//                {
//                    nexts.push_back({ j, cur });
//                }
//            }
//
//            q = move(nexts);
//        }
//
//        return -1;
//    }
//};

class Solution
{
public:
    int shortestPathLength(vector<vector<int>>& graph)
    {
        int n = graph.size();
        int end = (1 << n) - 1;
        queue<pair<int, int>> q;
        vector<vector<int>> passed(n, vector<int>(1 << n));
        for (int i = 0; i < n; ++i)
        {
            q.push({ i, 1 << i });
            passed[i][1 << i] = 1;
        }

        int dis;
        int cur;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            dis = passed[p.first][p.second];
            if (p.second == end)
            {
                return dis - 1;
            }

            for (int i : graph[p.first])
            {
                cur = p.second | (1 << i);
                if (passed[i][cur] == 0)
                {
                    passed[i][cur] = dis + 1;
                    q.push({ i, cur });
                }
            }
        }

        return -1;
    }
};