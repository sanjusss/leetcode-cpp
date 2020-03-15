#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<int> ps(n);
        for (int i = 0; i < n; ++i)
        {
            ps[i] = i;
        }

        sort(ps.begin(), ps.end(), [&efficiency](int a, int b)
            {
                return efficiency[a] > efficiency[b];
            });

        long ans = 0;
        long sum = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& i : ps)
        {
            q.push(speed[i]);
            sum += speed[i];
            if (q.size() > k)
            {
                sum -= q.top();
                q.pop();
            }

            ans = max(ans, sum * efficiency[i]);
        }

        return ans % (1000000007);
    }
};