#pragma once
#include "leetcode.h"

////O(N^3)
//class Solution 
//{
//public:
//    int findCircleNum(vector<vector<int>>& M) 
//    {
//        int N = M.size();
//        vector<int> circles(N);
//        int index = 0;
//        for (int i = 0; i < N; ++i)
//        {
//            if (circles[i] == 0)
//            {
//                circles[i] = ++index;
//            }
//
//            for (int j = i + 1; j < N; ++j)
//            {
//                if (M[i][j] == 0)
//                {
//                    continue;
//                }
//
//                if (circles[j] == 0)
//                {
//                    circles[j] = circles[i];
//                }
//                else if (circles[j] != circles[i])
//                {
//                    int temp = circles[j];
//                    for (auto& k : circles)
//                    {
//                        if (k == temp)
//                        {
//                            k = circles[i];
//                        }
//                    }
//                }
//            }
//        }
//
//        unordered_set<int> ans(circles.begin(), circles.end());
//        return ans.size();
//    }
//};

//O(N^2)
class Solution
{
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        int N = M.size();
        int ans = 0;
        vector<bool> visit(N);
        for (int i = 0; i < N; ++i)
        {
            if (visit[i])
            {
                continue;
            }

            ++ans;
            vector<int> q({ i });
            do
            {
                vector<int> next;
                for (int j : q)
                {
                    if (visit[j])
                    {
                        continue;
                    }

                    visit[j] = true;
                    for (int k = 0; k < N; ++k)
                    {
                        if (M[j][k] == 1)
                        {
                            next.push_back(k);
                        }
                    }
                }

                q = move(next);
            } while (q.empty() == false);
        }

        return ans;
    }
};