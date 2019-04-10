#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ////���
    //int numSquares(int n) 
    //{
    //    int max = (int)sqrt(n);
    //    while (max * max <= n)
    //    {
    //        ++max;
    //    }

    //    queue<int> q({ n });
    //    int num = 0;
    //    do
    //    {
    //        ++num;
    //        int length = q.size();
    //        for (int i = 0; i < length; ++i)
    //        {
    //            int current = q.front();
    //            q.pop();
    //            for (int j = 1; j < max; ++j)
    //            {
    //                int next = current - j * j;
    //                if (next == 0)
    //                {
    //                    return num;
    //                }
    //                else if (next > 0)
    //                {
    //                    q.push(next);
    //                }
    //            }
    //        }
    //    } while (q.empty() == false);
    //    return num;
    //}

    ////��̬�滮 f(n) = 1 + min( f(n - i ^ 2), i -> [1, sqrt(n)] Ч�ʵͣ����Ƽ�
    //int numSquares(int n)
    //{
    //    vector<int> f(n + 1, INT_MAX);
    //    f[0] = 0;
    //    for (int i = 1; i <= n; ++i)
    //    {
    //        for (int j = 1; j * j <= i; ++j)
    //        {
    //            f[i] = min(f[i - j * j] + 1, f[i]);
    //        }
    //    }

    //    return f[n];
    //}

    //��������ƽ���Ͷ������n������Ҫ�������ĸ������ɣ�С���ĸ����У����ض����� n=(4^a)*(8b+7)
    int numSquares(int n)
    {
        int t4 = n;
        while (t4 % 4 == 0)
        {
            t4 /= 4;
        }

        if (t4 % 8 == 7)
        {
            return 4;
        }

        for (int i = 0; i * i <= n; ++i)
        {
            int r = n - i * i;
            int j = (int)nearbyint(sqrt(r));
            if (j * j == r)
            {
                if (i == 0 || j == 0)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
        }

        return 3;
    }
};