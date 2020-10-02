#pragma once
#include "leetcode.h"

//class Solution
//{
//public:
//    string minWindow(string s, string t)
//    {
//        if (t.empty())
//        {
//            return "";
//        }
//
//        vector<int> tarray(128);
//        for (auto c : t)
//        {
//            ++tarray[c];
//        }
//
//        vector<int> rarray(128);
//        auto isSuccess = [&tarray, &rarray]()
//        {
//            for (int i = 0; i < 128; ++i)
//            {
//                if (tarray[i] > rarray[i])
//                {
//                    return false;
//                }
//            }
//
//            return true;
//        };
//
//        //[start,end)
//        int ansStart = -1;
//        int ansEnd = INT_MAX - 1;
//        //[left,right)
//        int left = 0;
//        int right = 0;
//        while (right < s.size())
//        {
//            while (right < s.size() && isSuccess() == false)
//            {
//                ++rarray[s[right]];
//                ++right;
//            }
//
//            while (isSuccess() && left < right)
//            {
//                if (right - left < ansEnd - ansStart)
//                {
//                    ansStart = left;
//                    ansEnd = right;
//                }
//
//                --rarray[s[left++]];
//            }
//        }
//
//        if (ansStart == -1)
//        {
//            return "";
//        }
//        else
//        {
//            return s.substr(ansStart, ansEnd - ansStart);
//        }
//    }
//};

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty())
        {
            return "";
        }

        vector<int> tarray(128);
        for (auto c : t)
        {
            ++tarray[c];
        }

        vector<int> rarray(128);
        for (auto c : s)
        {
            ++rarray[c];
        }

        for (int i = 0; i < 128; ++i)
        {
            if (tarray[i] > rarray[i])
            {
                return "";
            }
        }

        //[start,end)
        int ansStart = 0;
        int ansEnd = s.size();
        //[left,right)
        int left = 0;
        int right = s.size();
        while (rarray[s[right - 1]] > tarray[s[right - 1]])
        {
            --right;
            --rarray[s[right]];
        }

        while (true)
        {
            while (rarray[s[left]] > tarray[s[left]])
            {
                --rarray[s[left]];
                ++left;
            }

            if (right - left < ansEnd - ansStart)
            {
                ansStart = left;
                ansEnd = right;
            }

            if (right == s.size())
            {
                break;
            }

            while (right < s.size() && s[right] != s[left])
            {
                ++rarray[s[right]];
                ++right;
            }

            if (right < s.size())
            {
                ++rarray[s[right]];
                ++right;
            }
        }

        return s.substr(ansStart, ansEnd - ansStart);
    }
};

//class Solution 
//{
//public:
//    string minWindow(string s, string t) 
//    {
//        vector<int> tChars(CHAR_MAX + 1);
//        for (char i : t)
//        {
//            ++tChars[i];
//        }
//
//        bool found = false;
//        int rightMax = s.size();
//        int ansLeft = 0;
//        int ansRight = rightMax;
//        vector<int> sChars(CHAR_MAX + 1);
//        auto check = [&tChars, &sChars]()
//        {
//            for (int i = 0; i <= CHAR_MAX; ++i)
//            {
//                if (tChars[i] > sChars[i])
//                {
//                    return false;
//                }
//            }
//
//            return true;
//        };
//        int left = 0;
//        int right = 0;
//        while (right < rightMax)
//        {
//            ++sChars[s[right]];
//            ++right;
//            while (check())
//            {
//                found = true;
//                if (right - left < ansRight - ansLeft)
//                {
//                    ansLeft = left;
//                    ansRight = right;
//                }
//
//                --sChars[s[left]];
//                ++left;
//            }
//        }
//
//        if (found)
//        {
//            return s.substr(ansLeft, ansRight - ansLeft);
//        }
//        else
//        {
//            return string();
//        }
//    }
//};