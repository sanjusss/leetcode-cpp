#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int movingCount(int m, int n, int k) 
    {
        static const vector<pair<int, int>> dirs =
        {
            { -1, 0 },
            { 1, 0 },
            { 0, 1 },
            { 0, -1 },
        };

        int ans = 0;
        vector<pair<int, int>> q;
        vector<vector<bool>> pass(m, vector<bool>(n));
        q.push_back({ 0, 0 });
        while (q.empty() == false)
        {
            vector<pair<int, int>> nexts;
            for (auto& p : q)
            {
                if (p.first < 0 || p.first >= m ||
                    p.second < 0 || p.second >= n ||
                    pass[p.first][p.second])
                {
                    continue;
                }

                pass[p.first][p.second] = true;
                if (numSum(p.first) + numSum(p.second) <= k)
                {
                    ++ans;
                }
                else
                {
                    continue;
                }

                for (auto& d : dirs)
                {
                    nexts.push_back({ p.first + d.first, p.second + d.second });
                }
            }

            q = move(nexts);
        }

        return ans;
    }

private:
    int numSum(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
};