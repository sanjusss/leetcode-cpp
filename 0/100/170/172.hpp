#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int trailingZeroes(int n) 
//    {
//        int ans = 0;
//        for (int64_t i = 5; i <= n; i *= 5)
//        {
//            ans += n / i;
//        }
//
//        return ans;
//    }
//};

//������ɸ���ĸ�д����ֹ�����
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans += n / 5;
            n /= 5;
        }

        return ans;
    }
};