#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int shortestSubarray(vector<int>& A, int K) 
//    {
//        int size = A.size();
//        deque<pair<int, int>> dq;
//        dq.push_back({ -1, 0 });
//        int ans = INT_MAX;
//        int sum = 0;
//        for (int i = 0; i < size; ++i)
//        {
//            sum += A[i];
//            if (sum - dq.front().second >= K)
//            {
//                auto pos = upper_bound(dq.begin(), dq.end(), pair<int, int>(0, sum - K) , [](const pair<int, int>& a, const pair<int, int>& b)
//                    {
//                        return a.second < b.second;
//                    });
//                if (pos != dq.begin())
//                {
//                    ans = min(ans, i - prev(pos)->first);
//                }
//            }
//
//            while (!dq.empty() && sum <= dq.back().second)
//            {
//                dq.pop_back();
//            }
//
//            dq.push_back({ i, sum });
//        }
//
//        return ans == INT_MAX ? - 1 : ans;
//    }
//};

class Solution
{
public:
    int shortestSubarray(vector<int>& A, int K)
    {
        int size = A.size();
        deque<pair<int, int>> dq;
        dq.push_back({ -1, 0 });
        int ans = INT_MAX;
        int sum = 0;
        for (int i = 0; i < size; ++i)
        {
            sum += A[i];
            while (!dq.empty() && sum <= dq.back().second)
            {
                dq.pop_back();
            }

            dq.push_back({ i, sum });
            while (!dq.empty() && sum - dq.front().second >= K)
            {
                ans = min(ans, i - dq.front().first);
                dq.pop_front();
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};