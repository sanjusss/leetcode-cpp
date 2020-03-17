#pragma once
#include "leetcode.h"

namespace _0224 
{

    class Solution
    {
        struct unit
        {
            long num = 0;
            char op = 0;

            unit() {}
            unit(long n) : num(n) {}
            unit(char c) : op(c) {}
        };

    public:
        int calculate(string s)
        {
            vector<unit> q;
            stack<char> ops;
            long n = 0;
            bool setN = false;
            for (auto i : s)
            {
                if (isdigit(i))
                {
                    n = n * 10 + i - '0';
                    setN = true;
                    continue;
                }
                else if (i == ' ')
                {
                    continue;
                }

                if (setN)
                {
                    q.push_back(n);
                    n = 0;
                    setN = false;
                }

                if (i == ')')
                {
                    while (ops.top() != '(')
                    {
                        q.push_back(ops.top());
                        ops.pop();
                    }

                    ops.pop();
                }
                else if (i == '(')
                {
                    ops.push(i);
                }
                else
                {
                    if (ops.empty() == false && (ops.top() == '+' || ops.top() == '-'))
                    {
                        q.push_back(ops.top());
                        ops.pop();
                    }

                    ops.push(i);
                }
            }

            if (setN)
            {
                q.push_back(n);
            }

            while (ops.empty() == false)
            {
                q.push_back(ops.top());
                ops.pop();
            }

            stack<long> nums;
            for (int i = 0; i < q.size(); ++i)
            {
                if (q[i].op == 0)
                {
                    nums.push(q[i].num);
                }
                else
                {
                    int b = nums.top();
                    nums.pop();
                    if (q[i].op == '+')
                    {
                        nums.top() += b;
                    }
                    else
                    {
                        nums.top() -= b;
                    }
                }
            }

            return nums.top();
        }
    };

}