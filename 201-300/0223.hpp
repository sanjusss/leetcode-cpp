#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
//    {
//        long ans = 0;
//        ans += ((long)C - (long)A) * ((long)D - (long)B);
//        ans += ((long)G - (long)E) * ((long)H - (long)F);
//        long width = ((long)C - (long)A) + ((long)G - (long)E) - (max((long)G, (long)C) - min((long)A, (long)E));
//        if (width > 0)
//        {
//            long height = ((long)D - (long)B) + ((long)H - (long)F) - (max((long)D, (long)H) - min((long)B, (long)F));
//            if (height > 0)
//            {
//                ans -= width * height;
//            }
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int ans = 0;
        if (!(G < A || C < E ||
            H < B || D < F))
        {
            ans -= (max(A, E) - min(C, G)) * (max(B, F) - min(D, H));
        }

        ans += (C - A) * (D - B);
        ans += (G - E) * (H - F);
        return ans;
    }
};