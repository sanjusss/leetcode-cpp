#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    bool isHappy(int n) 
//    {
//        unordered_set<int> used;
//        int sum;
//        int temp;
//        while (true)
//        {
//            if (n == 1)
//            {
//                return true;
//            }
//
//            if (used.count(n) > 0)
//            {
//                return false;
//            }
//            else
//            {
//                used.insert(n);
//            }
//
//            sum = 0;
//            while (n != 0)
//            {
//                temp = n % 10;
//                sum += temp * temp;
//                n /= 10;
//            }
//
//            n = sum;
//        }
//
//        return false;
//    }
//};

class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1)
        {
            return true;
        }

        int slow = n;
        int fast = n;
        do
        {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != 1 && slow != fast);
        return slow == 1;
    }

private:
    int next(int n)
    {
        int sum = 0;
        int temp;
        while (n > 0)
        {
            temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }

        return sum;
    }
};