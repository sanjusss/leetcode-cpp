#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;
        for (auto& i : tokens)
        {
            if (i == "+")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a + b);
            }
            else if (i == "-")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a - b);
            }
            else if (i == "*")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a * b);
            }
            else if (i == "/")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a / b);
            }
            else
            {
                s.push(stoi(i));
            }
        }

        if (s.empty())
        {
            return 0;
        }
        else
        {
            return s.top();
        }
    }
};