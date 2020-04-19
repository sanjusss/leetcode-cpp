#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string reformat(string s) 
    {
        string a;
        string n;
        for (auto i : s)
        {
            if (isdigit(i))
            {
                n.push_back(i);
            }
            else
            {
                a.push_back(i);
            }
        }

        if (abs((int)a.size() - (int)n.size()) > 1)
        {
            return string();
        }

        if (a.size() < n.size())
        {
            a.swap(n);
        }

        string ans;
        int size = a.size() + n.size();
        for (int i = 0; i < size; ++i)
        {
            if (i % 2 == 0)
            {
                ans.push_back(a[i / 2]);
            }
            else
            {
                ans.push_back(n[i / 2]);
            }
        }

        return ans;
    }
};