#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    string longestCommonPrefix(vector<string>& strs) 
//    {
//        if (strs.size() == 0)
//        {
//            return string();
//        }
//
//        int length = INT_MAX;
//        for (auto& s : strs)
//        {
//            length = min((int)s.length(), length);
//        }
//
//        string res;
//        int strCount = strs.size();
//        for (int i = 0; i < length; ++i)
//        {
//            for (int j = 1; j < strCount; ++j)
//            {
//                if (strs[0][i] != strs[j][i])
//                {
//                    return res;
//                }
//            }
//
//            res += strs[0][i];
//        }
//
//        return res;
//    }
//};

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty())
        {
            return string();
        }

        int length = 0;
        string& t = strs.front();
        bool success = true;
        while (length < t.size())
        {
            for (int i = 1; i < strs.size(); ++i)
            {
                if (strs[i].size() <= length || strs[i][length] != t[length])
                {
                    success = false;
                    break;
                }
            }

            if (success)
            {
                ++length;
            }
            else
            {
                break;
            }
        }

        return t.substr(0, length);
    }
};