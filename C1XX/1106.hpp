#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool parseBoolExpr(string expression) 
    {
        stack<char> s;
        for (auto c : expression)
        {
            if (c == '(' || c == ',')
            {
                continue;
            }
            else if (c == ')')
            {
                bool res;
                vector<bool> temps;
                while (s.top() == 'f' || s.top() == 't')
                {
                    temps.push_back(s.top() == 't');
                    s.pop();
                }

                char o = s.top();
                s.pop();
                if (o == '!')
                {
                    res = !temps.front();
                }
                else if (o == '|')
                {
                    res = false;
                    for (auto t : temps)
                    {
                        res |= t;
                    }
                }
                else
                {
                    res = true;
                    for (auto t : temps)
                    {
                        res &= t;
                    }
                }

                s.push(res ? 't' : 'f');
            }
            else
            {
                s.push(c);
            }
        }

        return s.top() == 't';
    }
};