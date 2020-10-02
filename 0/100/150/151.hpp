#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    string reverseWords(string s) 
//    {
//        string temp;
//        string res;
//        for (auto i : s)
//        {
//            if (i == ' ')
//            {
//                if (temp.empty() == false)
//                {
//                    if (res.empty())
//                    {
//                        res = temp;
//                    }
//                    else
//                    {
//                        res = temp + ' ' + res;
//                    }
//
//                    temp.clear();
//                }
//            }
//            else 
//            {
//                temp += i;
//            }
//        }
//
//        if (temp.empty() == false)
//        {
//            if (res.empty())
//            {
//                res = temp;
//            }
//            else
//            {
//                res = temp + ' ' + res;
//            }
//        }
//
//        return res;
//    }
//};

//class Solution
//{
//public:
//    string reverseWords(string s)
//    {
//        string ans;
//        int end = -1;
//        for (int i = s.size() - 1; i >= 0; --i)
//        {
//            if (s[i] == ' ')
//            {
//                if (end != -1)
//                {
//                    if (ans.empty() == false)
//                    {
//                        ans.push_back(' ');
//                    }
//
//                    for (int j = i + 1; j <= end; ++j)
//                    {
//                        ans.push_back(s[j]);
//                    }
//
//                    end = -1;
//                }
//            }
//            else
//            {
//                if (end == -1)
//                {
//                    end = i;
//                }
//            }
//        }
//
//        if (end != -1)
//        {
//            if (ans.empty() == false)
//            {
//                ans.push_back(' ');
//            }
//
//            for (int j = 0; j <= end; ++j)
//            {
//                ans.push_back(s[j]);
//            }
//        }
//
//        return ans;
//    }
//};

//¿Õ¼ä¸´ÔÓ¶ÈO(1)
//class Solution
//{
//public:
//    string reverseWords(string s)
//    {
//        while (s.empty() == false && s.back() == ' ')
//        {
//            s.pop_back();
//        }
//
//        reverse(s.begin(), s.end());
//
//        while (s.empty() == false && s.back() == ' ')
//        {
//            s.pop_back();
//        }
//
//        int begin = -1;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i] == ' ')
//            {
//                if (begin == -1)
//                {
//                    s.erase(i, 1);
//                    --i;
//                }
//                else
//                {
//                    reverse(next(s.begin(), begin), next(s.begin(), i));
//                    begin = -1;
//                }
//            }
//            else
//            {
//                if (begin == -1)
//                {
//                    begin = i;
//                }
//            }
//        }
//
//        if (begin != -1)
//        {
//            reverse(next(s.begin(), begin), s.end());
//        }
//
//        return s;
//    }
//};

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int end = s.size();
        int begin = -1;
        int last = -1;
        for (int i = 0; i < end; ++i)
        {
            if (s[i] == ' ')
            {
                if (begin == -1)
                {
                    int j = 0;
                    while (i + j < end && s[i + j] == ' ')
                    {
                        ++j;
                    }

                    end -= j;
                    for (int k = i; k < end; ++k)
                    {
                        s[k] = s[k + j];
                    }

                    if (i != end)
                    {
                        last = i;
                        begin = i;
                    }
                }
                else
                {
                    reverse(s.begin() + begin, s.begin() + i);
                    begin = -1;
                }
            }
            else
            {
                last = i;
                if (begin == -1)
                {
                    begin = i;
                }
            }
        }

        if (begin != -1)
        {
            reverse(s.begin() + begin, s.begin() + end);
        }

        if (last + 1 < s.size())
        {
            s.erase(last + 1);
        }

        return s;
    }
};