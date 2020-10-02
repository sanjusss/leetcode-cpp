#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    string convert(string s, int numRows) 
//    {
//        int size = s.size();
//        int rowLength = numRows * 2 - 2;
//        if (rowLength == 0)
//        {
//            return s;
//        }
//
//        vector<string> lines(numRows);
//        for (int i = 0; i < size; ++i)
//        {
//            int row = i % rowLength;
//            if (row >= numRows)
//            {
//                row = rowLength - row;
//            }
//
//            lines[row].push_back(s[i]);
//        }
//
//        string ans;
//        for (auto& i : lines)
//        {
//            ans += i;
//        }
//
//        return ans;
//    }
//};

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        int size = s.size();
        int step = numRows * 2 - 2;
        if (step == 0)
        {
            return s;
        }

        string ans;
        for (int i = 0; i < numRows; ++i)
        {
            if (i == 0 || i == numRows - 1)
            {
                for (int j = i; j < size; j += step)
                {
                    ans.push_back(s[j]);
                }
            }
            else
            {
                int next;
                for (int j = i; j < size; j += step)
                {
                    ans.push_back(s[j]);
                    next = j + step - 2 * i;
                    if (next < size)
                    {
                        ans.push_back(s[next]);
                    }
                }
            }
        }

        return ans;
    }
};