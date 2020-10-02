#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int numJewelsInStones(string J, string S) 
//    {
//        set<char> js;
//        for (auto i : J)
//        {
//            js.insert(i);
//        }
//
//        int count = 0;
//        for (auto i : S)
//        {
//            if (js.find(i) != js.end())
//            {
//                ++count;
//            }
//        }
//
//        return count;
//    }
//};
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int count = 0;
        for (auto i : S)
        {
            if (J.find_first_of(i) != string::npos)
            {
                ++count;
            }
        }

        return count;
    }
};