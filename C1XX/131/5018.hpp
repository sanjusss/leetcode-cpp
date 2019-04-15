#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) 
    {
        vector<bool> res;
        vector<string> patternList = split(pattern);
        for (auto i : queries)
        {
            res.push_back(match(i, patternList));
        }

        return res;
    }

private:
    static bool match(const string& query, const vector<string>& patternList)
    {
        vector<string> queryList = split(query);
        int length = queryList.size();
        if (length != patternList.size())
        {
            return false;
        }

        for (int i = 0; i < length; ++i)
        {
            if (match(queryList[i], patternList[i]) == false)
            {
                return false;
            }
        }

        return true;
    }

    static bool match(const string& q, const string& p)
    {
        int qLength = q.length();
        int pLength = p.length();
        int qi = 0;
        int pi = 0;
        while (qi < qLength && pi < pLength)
        {
            if (q[qi] == p[pi])
            {
                ++pi;
            }

            ++qi;
        }

        return pi == pLength;
    }

    static vector<string> split(const string& s)
    {
        vector<string> res;
        string temp;
        for (auto i : s)
        {
            if (isupper(i))
            {
                if (temp.empty() == false)
                {
                    res.push_back(temp);
                    temp.clear();
                }

                temp += i;
            }
            else if (temp.empty() == false)
            {
                temp += i;
            }
        }

        if (temp.empty() == false)
        {
            res.push_back(temp);
        }

        return res;
    }
};