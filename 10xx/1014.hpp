#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int maxScoreSightseeingPair(vector<int>& A) 
//    {
//        int ans = 0;
//        int prev = 0;
//        for (int i = 1; i < A.size(); ++i)
//        {
//            ans = max(ans, A[i] + A[prev] + prev - i);
//            if (A[i] + i > A[prev] + prev)
//            {
//                prev = i;
//            }
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int>& A)
    {
        int ans = 0;
        int prev = A[0];
        for (int i = 1; i < A.size(); ++i)
        {
            ans = max(ans, A[i] + prev - i);
            prev = max(prev, A[i] + i);
        }

        return ans;
    }
};