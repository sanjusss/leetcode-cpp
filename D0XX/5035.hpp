#pragma once
#include "leetcode.h"
#include <iostream>

class Solution
{
public:
    int maximumMinimumPath(vector<vector<int>>& A)
    {
        int R = A.size();
        int C = A[0].size();
        int minval = INT_MAX;
        int maxval = INT_MIN;
        for (auto i : A)
        {
            for (auto j : i)
            {
                minval = min(minval, j);
                maxval = max(maxval, j);
            }
        }

        while (maxval > minval + 1)
        {
            int mid = (minval + maxval + 1) / 2;
            if (isReachable(A, R, C, mid))
            {
                minval = mid;
            }
            else
            {
                maxval = mid;
            }
        }

        return isReachable(A, R, C, maxval) ? maxval : minval;
    }

private:
    bool isReachable(vector<vector<int>>& A, int R, int C, int minval)
    {
        queue<pair<int, int>> q;
        vector<vector<bool>> pass(R, vector<bool>(C, false));
        q.push({ 0, 0 });
        while (q.empty() == false)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (pass[x][y] || A[x][y] < minval)
            {
                continue;
            }

            pass[x][y] = true;

            if (x > 0)
            {
                q.push({ x - 1, y });
            }

            if (x < R - 1)
            {
                q.push({ x + 1, y });
            }

            if (y > 0)
            {
                q.push({ x, y - 1 });
            }

            if (y < C - 1)
            {
                q.push({ x, y + 1 });
            }
        }

        return pass[R - 1][C - 1];
    }
};