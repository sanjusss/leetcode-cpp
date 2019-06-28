#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int lengthOfLongestSubstring(string s) 
//    {
//        int start = 0;
//        int size = s.length();
//        int length = s.empty() ? 0 : 1;
//        for (int i = 1; i < size; ++i)
//        {
//            for (int j = i - 1; j >= start; --j)
//            {
//                if (s[j] == s[i])
//                {
//                    start = j + 1;
//                    break;
//                }
//            }
//
//            length = max(i - start + 1, length);
//        }
//
//        return length;
//    }
//};
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int pos[CHAR_MAX - CHAR_MIN + 1] = { 0 };
        int size = s.size();
        int length = 0;
        int start = 0;
        for (int end = 0; end < size; ++end)
        {
            if (pos[s[end]] > start)
            {
                start = pos[s[end]];
            }

            length = max(length, end - start + 1);
            pos[s[end]] = end + 1;
        }

        return length;
    }
};