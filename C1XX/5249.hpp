#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int> lefts;
        vector<int> removes;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                lefts.push(i);
            }
            else if (s[i] == ')')
            {
                if (lefts.empty())
                {
                    removes.push_back(i);
                }
                else
                {
                    lefts.pop();
                }
            }
        }

        while (lefts.empty() == false)
        {
            removes.push_back(lefts.top());
            lefts.pop();
        }

        sort(removes.begin(), removes.end(), greater<int>());
        for (int i : removes)
        {
            s = s.erase(i, 1);
        }

        return s;
    }
};