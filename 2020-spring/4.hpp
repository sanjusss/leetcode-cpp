#pragma once
#include "leetcode.h"

//class Solution
//{
//public:
//    int minJump(vector<int>& jump)
//    {
//        int n = jump.size();
//        vector<int> rights(n);
//        vector<int> steps(n, INT_MAX / 2);
//        vector<int> q;
//        int left = -1;
//        for (int i = 0; i < n; ++i)
//        {
//            rights[i] = i + jump[i];
//            if (rights[i] >= n)
//            {
//                steps[i] = 1;
//                if (left < 0)
//                {
//                    left = i;
//                }
//            }
//            else
//            {
//                q.push_back(i);
//            }
//        }
//
//        while (steps[0] >= INT_MAX / 2 && q.empty() == false)
//        {
//            vector<int> nexts;
//            int nextLeft = left;
//            for (int i : q)
//            {
//                if (rights[i] < n)
//                {
//                    steps[i] = min(steps[i], 1 + steps[rights[i]]);
//                }
//
//                if (left < i)
//                {
//                    steps[i] = min(steps[i], 1 + steps[left]);
//                }
//
//                if (steps[i] >= INT_MAX / 2)
//                {
//                    nexts.push_back(i);
//                }
//                else
//                {
//                    nextLeft = min(nextLeft, i);
//                }
//            }
//
//            left = nextLeft;
//            q = move(nexts);
//        }
//
//        return steps[0];
//    }
//};

class Solution
{
public:
    int minJump(vector<int>& jump)
    {
        int n = jump.size();
        vector<int> steps(n, INT_MAX / 2);
        vector<vector<int>> nexts(n);
        vector<int> q;
        int left = -1;
        int prevLeft = n;
        for (int i = 0; i < n; ++i)
        {
            int right = i + jump[i];
            if (right >= n)
            {
                steps[i] = 1;
                q.push_back(i);
                if (left < 0)
                {
                    left = i;
                }
            }
            else
            {
                nexts[right].push_back(i);
            }
        }

        while (left > 0)
        {
            vector<int> nq;
            int nextLeft = left;
            for (int i : q)
            {
                for (int j : nexts[i])
                {
                    if (steps[j] >= INT_MAX / 2)
                    {
                        steps[j] = steps[i] + 1;
                        nq.push_back(j);
                        nextLeft = min(nextLeft, j);
                    }
                }
            }

            for (int i = left + 1; i < prevLeft; ++i)
            {
                if (steps[i] >= INT_MAX / 2)
                {
                    nq.push_back(i);
                }

                steps[i] = min(steps[i], steps[left] + 1);
            }

            prevLeft = left;
            left = nextLeft;
            q = move(nq);
        }

        return steps[0];
    }
};