#pragma once
#include "leetcode.h"

class Solution 
{
public:
    //��Ȼʱ�临�Ӷ�O(n^3)�������ڿռ�ռ��O(1)����ʡ������ռ��ʱ�䣬ʵ���ٶȺܿ졣
    int longestArithSeqLength(vector<int>& A) 
    {
        int res = 1;
        int length = A.size();
        int interval = 0;
        for (int i = 0; i < length; ++i)
        {
            for (int j = i + 1; j < length; ++j)
            {
                int size = 2;
                int v = A[j] - A[i];
                int next = A[j] + v;
                for (int k = j + 1; k < length; ++k)
                {
                    if (A[k] == next)
                    {
                        next += v;
                        ++size;
                    }
                }

                res = max(res, size);
            }
        }

        return res;
    }
};