#pragma once
#include "leetcode.h"

//class Solution
//{
//public:
//    bool isPalindrome(int x)
//    {
//        if (x < 0)
//        {
//            return false;
//        }
//
//        if (x == 0)
//        {
//            return true;
//        }
//
//        vector<int> v;
//        while (x > 0)
//        {
//            v.push_back(x % 10);
//            x /= 10;
//        }
//
//        int size = v.size();
//        for (int i = size / 2; i >= 0; --i)
//        {
//            if (v[i] != v[size - 1 - i])
//            {
//                return false;
//            }
//        }
//
//        return true;
//    }
//};

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        if (x == 0)
        {
            return true;
        }

        if (x % 10 == 0)
        {
            return false;
        }

        int right = 0;
        while (x > right)
        {
            right = right * 10 + x % 10;
            x /= 10;
        }

        return x == right || x == right / 10;
    }
};