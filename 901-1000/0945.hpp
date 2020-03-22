#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int minIncrementForUnique(vector<int>& A)
//    {
//        array<int, 80000> ns;
//        ns.fill(0);
//        int maxI = 0;
//        int minI = 40000;
//        for (auto i : A)
//        {
//            maxI = max(maxI, i);
//            minI = min(minI, i);
//            ++ns[i];
//        }
//
//        int ans = 0;
//        int remain = 0;
//        for (int j = minI; j <= maxI || remain > 0; ++j)
//        {
//            ans += remain;
//            if (ns[j] == 0)
//            {
//                if (remain > 0)
//                {
//                    --remain;
//                }
//            }
//            else
//            {
//                remain += ns[j] - 1;
//            }
//        }
//
//        return ans;
//    }
//};

//��ns���ȫ�ֱ������ٶȿ�������Լ50%��(lll�V�ةV)
array<int, 80000> ns;
class Solution
{
public:
    int minIncrementForUnique(vector<int>& A)
    {
        ns.fill(0);
        int maxI = 0;
        int minI = 40000;
        for (auto i : A)
        {
            maxI = max(maxI, i);
            minI = min(minI, i);
            ++ns[i];
        }

        int ans = 0;
        int remain = 0;
        for (int j = minI; j <= maxI || remain > 0; ++j)
        {
            ans += remain;
            if (ns[j] == 0)
            {
                if (remain > 0)
                {
                    --remain;
                }
            }
            else
            {
                remain += ns[j] - 1;
            }
        }

        return ans;
    }
};