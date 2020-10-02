#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int longestValidParentheses(string s) 
//    {
//        stack<int> lefts;
//        int longest = 0;
//        int start = -1;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i] == '(')
//            {
//                lefts.push(i);
//            }
//            else if (lefts.empty())
//            {
//                start = i;
//            }
//            else
//            {
//                lefts.pop();
//                if (lefts.empty())
//                {
//                    longest = max(longest, i - start);
//                }
//                else
//                {
//                    longest = max(longest, i - lefts.top());
//                }
//            }
//        }
//
//        return longest;
//    }
//};
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int longest = 0;
        int left = 0;
        int right = 0;
        for (auto i : s)
        {
            if (i == '(')
            {
                ++left;
            }
            else
            {
                ++right;
            }

            if (left == right)
            {
                longest = max(longest, left + right);
            }
            else if (right > left)
            {
                right = 0;
                left = 0;
            }
        }

        right = 0;
        left = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == '(')
            {
                ++left;
            }
            else
            {
                ++right;
            }

            if (left == right)
            {
                longest = max(longest, left + right);
            }
            else if (left > right)
            {
                right = 0;
                left = 0;
            }
        }

        return longest;
    }
};