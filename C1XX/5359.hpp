#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int, int>> ps(n);
        for (int i = 0; i < n; ++i)
        {
            ps[i] = { speed[i], efficiency[i] };
        }

        sort(ps.begin(), ps.end(), [](const pair<int, int>& a, const pair<int, int>& b)
            {
                return a.second > b.second;
            });

        long ans = 0;
        long sum = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& p : ps)
        {
            q.push(p.first);
            sum += p.first;
            if (q.size() > k)
            {
                sum -= q.top();
                q.pop();
            }

            ans = max(ans, sum * p.second);
        }

        return ans % (1000000007);
    }
};