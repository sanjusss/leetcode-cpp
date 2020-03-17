#pragma once
#include "leetcode.h"


namespace _0227
{
    //class Solution
    //{
    //    struct unit
    //    {
    //        long num = 0;
    //        char op = 0;
    //        unit() {}
    //        unit(long n) : num(n) {}
    //        unit(char o) : op(o) {}
    //    };

    //public:
    //    int calculate(string s)
    //    {
    //        vector<unit> q;
    //        long n = 0;
    //        bool setN = false;
    //        stack<char> ops;
    //        for (char c : s)
    //        {
    //            if (isdigit(c))
    //            {
    //                n = n * 10 + c - '0';
    //                setN = true;
    //                continue;
    //            }
    //            else if (c == ' ')
    //            {
    //                continue;
    //            }

    //            if (setN)
    //            {
    //                q.push_back(n);
    //                n = 0;
    //                setN = false;
    //            }

    //            while (ops.empty() == false && level(ops.top()) >= level(c))
    //            {
    //                q.push_back(ops.top());
    //                ops.pop();
    //            }

    //            ops.push(c);
    //        }

    //        if (setN)
    //        {
    //            q.push_back(n);
    //            n = 0;
    //            setN = false;
    //        }

    //        while (ops.empty() == false)
    //        {
    //            q.push_back(ops.top());
    //            ops.pop();
    //        }

    //        stack<long> nums;
    //        for (auto& u : q)
    //        {
    //            if (u.op == 0)
    //            {
    //                nums.push(u.num);
    //            }
    //            else
    //            {
    //                long b = nums.top();
    //                nums.pop();
    //                nums.top() = calc(u.op, nums.top(), b);
    //            }
    //        }

    //        return nums.top();
    //    }

    //private:
    //    int level(char op)
    //    {
    //        switch (op)
    //        {
    //        case '*':
    //        case '/':
    //            return 2;

    //        case '+':
    //        case '-':
    //            return 1;

    //        default:
    //            return 0;
    //        }
    //    }

    //    long calc(char op, long a, long b)
    //    {
    //        switch (op)
    //        {
    //        case '*':
    //            return a * b;

    //        case '/':
    //            return a / b;

    //        case '+':
    //            return a + b;

    //        case '-':
    //            return a - b;

    //        default:
    //            return 0;
    //        }
    //    }
    //};

    //ø’º‰∏¥‘”∂»O(1)
    class Solution 
    {
    public:
        int calculate(string s) 
        {
            long pre = 0;
            long cur = 0;
            long next = 0;
            char lastOp = '+';
            for (char c : s)
            {
                if (isdigit(c))
                {
                    next = next * 10 + c - '0';
                }
                else if (c == ' ')
                {
                    continue;
                }
                else
                {
                    calc(pre, cur, next, lastOp);
                    lastOp = c;
                }
            }

            calc(pre, cur, next, lastOp);
            return pre + cur;
        }

    private:
        void calc(long& pre, long& cur, long& next, char op)
        {
            if (op == '+' || op == '-')
            {
                pre += cur;
                if (op == '+')
                {
                    cur = next;
                }
                else
                {
                    cur = -next;
                }
            }
            else
            {
                if (op == '*')
                {
                    cur *= next;
                }
                else
                {
                    cur /= next;
                }
            }

            next = 0;
        }
    };
}