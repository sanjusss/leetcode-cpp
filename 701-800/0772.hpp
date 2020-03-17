#pragma once
#include "leetcode.h"

class Solution
{
public:
    int calculate(string s)
    {
        vector<long> q;
        long n = 0;
        bool setN = false;
        char lastVaildC = 0;
        stack<long> ops;
        for (char c : s)
        {
            if (c == ' ')
            {
                continue;
            }

            if (isdigit(c))
            {
                n = n * 10 + c - '0';
                setN = true;
                lastVaildC = c;
                continue;
            }

            if (setN)
            {
                q.push_back(n);
                n = 0;
                setN = false;
            }

            if (c == '(')
            {
                ops.push(c);
            }
            else if (c == ')')
            {
                while (ops.empty() == false && ops.top() != '(')
                {
                    q.push_back(ops.top());
                    ops.pop();
                }

                if (ops.empty() == false)
                {
                    ops.pop();
                }
            }
            else
            {
                long op = char2op(c, isA(lastVaildC) == false);
                while (ops.empty() == false && level(ops.top()) >= level(op))
                {
                    q.push_back(ops.top());
                    ops.pop();
                }

                ops.push(op);
            }

            lastVaildC = c;
        }

        if (setN)
        {
            q.push_back(n);
            n = 0;
            setN = false;
        }

        while (ops.empty() == false)
        {
            q.push_back(ops.top());
            ops.pop();
        }

        stack<long> nums;
        for (auto& u : q)
        {
            if (u >= 0)
            {
                nums.push(u);
            }
            else
            {
                if (paramsCount(u) == 1)
                {
                    nums.top() = calc(u, nums.top());
                }
                else
                {
                    long b = nums.top();
                    nums.pop();
                    nums.top() = calc(u, nums.top(), b);
                }
            }
        }

        return nums.top();
    }

private:
    bool isA(char c)
    {
        return isdigit(c) || c == ')';
    }

    int level(long op)
    {
        if (op >= 0)
        {
            return 0;
        }
        else
        {
            return (-op + 1) / 2;
        }
    }

    long char2op(char c, bool right)
    {
        switch (c)
        {
        case '*':
            return right ? -8 : -4;

        case '/':
            return right ? -7 : -3;

        case '+':
            return right ? -6 : -2;

        case '-':
            return right ? -5 : -1;

        default:
            return 0;
        }
    }

    int calc(long op, long a, long b)
    {
        switch (op)
        {
        case -4:
            return a * b;

        case -3:
            return a / b;

        case -2:
            return a + b;

        case -1:
            return a - b;

        default:
            return 0;
        }
    }

    int calc(long op, long a)
    {
        switch (op)
        {
        case -5:
            return -a;

        default:
            return a;
        }
    }

    int paramsCount(long op)
    {
        if (op <= -5)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
};