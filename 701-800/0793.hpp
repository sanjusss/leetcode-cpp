#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int preimageSizeFZF(int K) 
//    {
//        uint64_t left = 0;
//        uint64_t right = UINT64_MAX;
//        uint64_t mid;
//        while (left < right)
//        {
//            mid = left + (right - left) / 2;
//            if (trailingZeroes(mid) > K)
//            {
//                right = mid;
//            }
//            else
//            {
//                left = mid + 1;
//            }
//        }
//
//        uint64_t upper = right;
//        left = 0;
//        while (left < right)
//        {
//            mid = left + (right - left) / 2;
//            if (trailingZeroes(mid) >= K)
//            {
//                right = mid;
//            }
//            else
//            {
//                left = mid + 1;
//            }
//        }
//
//        return upper - left;
//    }
//
//private:
//    uint64_t trailingZeroes(uint64_t n)
//    {
//        uint64_t ans = 0;
//        while (n > 0)
//        {
//            ans += n / 5;
//            n /= 5;
//        }
//
//        return ans;
//    }
//};

//实际上只可能存在0和5两种答案，可以简化。
class Solution
{
public:
    int preimageSizeFZF(int K)
    {
        uint64_t left = 0;
        uint64_t right = UINT64_MAX;
        uint64_t mid;
        uint64_t test;
        while (left < right)
        {
            mid = (left + right) / 2;
            mid = left + (right - left) / 2;
            if (test == K)
            {
                return 5;
            }
            else if (test > K)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return 0;
    }

private:
    uint64_t trailingZeroes(uint64_t n)
    {
        uint64_t ans = 0;
        while (n > 0)
        {
            ans += n / 5;
            n /= 5;
        }

        return ans;
    }
};