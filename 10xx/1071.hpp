#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    string gcdOfStrings(string str1, string str2) 
//    {
//        //1 <= str1.length <= 1000 && 1 <= str2.length <= 1000
//        int maxSize = gcd(str1.size(), str2.size());
//        for (int i = maxSize; i > 0; --i)
//        {
//            if (maxSize % i != 0)
//            {
//                continue;
//            }
//
//            auto jb = str1.begin();
//            auto je = next(jb, i);
//            auto kb = je;
//            auto ke = je;
//            bool success = true;
//            while (kb != str1.end())
//            {
//                ke = next(kb, i);
//                if (equal(jb, je, kb, ke) == false)
//                {
//                    success = false;
//                    break;
//                }
//
//                kb = ke;
//            } 
//
//            if (success == false)
//            {
//                continue;
//            }
//
//            kb = str2.begin();
//            while (kb != str2.end())
//            {
//                ke = next(kb, i);
//                if (equal(jb, je, kb, ke) == false)
//                {
//                    success = false;
//                    break;
//                }
//
//                kb = ke;
//            }
//
//            if (success)
//            {
//                return string(jb, je);
//            }
//        }
//
//        return string();
//    }
//
//private:
//    int gcd(int a, int b)
//    {
//        if (a == 0)
//        {
//            return b;
//        }
//        else
//        {
//            return gcd(b % a, a);
//        }
//    }
//};

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 == str2 + str1)
        {
            return str1.substr(0, gcd(str1.size(), str2.size()));
        }
        else
        {
            return string();
        }
    }

private:
    int gcd(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        else
        {
            return gcd(b % a, a);
        }
    }
};