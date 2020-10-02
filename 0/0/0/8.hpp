#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int myAtoi(string str) 
//    {
//        int64_t res = 0;
//        int64_t sign = 1;
//        bool setSign = false;
//        bool setValue = false;
//        for (auto i : str)
//        {
//            if (i == ' ')
//            {
//                if (setSign || setValue)
//                {
//                    break;
//                }
//                else
//                {
//                    continue;
//                }
//            }
//            else if (i == '-')
//            {
//                if (setSign || setValue)
//                {
//                    break;
//                }
//                else
//                {
//                    sign = -1;
//                    setSign = true;
//                }
//            }
//            else if (i == '+')
//            {
//                if (setSign || setValue)
//                {
//                    break;
//                }
//                else
//                {
//                    setSign = true;
//                }
//            }
//            else if (isdigit(i))
//            {
//                res = res * 10 + sign * (i - '0');
//                setValue = true;
//                if (res < INT32_MIN)
//                {
//                    res = INT32_MIN;
//                    break;
//                }
//                else if (res > INT32_MAX)
//                {
//                    res = INT32_MAX;
//                    break;
//                }
//            }
//            else
//            {
//                break;
//            }
//        }
//
//        return res;
//    }
//};


class Solution
{
public:
    int myAtoi(string str)
    {
        //状态： 0 开始， 1 确认符号， 2 处理数字， 3 结束
        //动作： 0 空格， 1 -/+， 2 数字， 3 其他
        vector<vector<int>> table =
        {
            { 0, 1, 2, 3 },
            { 3, 3, 2, 3 },
            { 3, 3, 2, 3 },
            { 3, 3, 3, 3 }
        };

        int state = 0;
        bool sign = true;
        int64_t ans = 0;
        for (auto i : str)
        {
            int act;
            if (i >= '0' && i <= '9')
            {
                act = 2;
            }
            else if (i == ' ')
            {
                act = 0;
            }
            else if (i == '-' || i == '+')
            {
                act = 1;
            }
            else
            {
                act = 3;
            }

            state = table[state][act];
            if (state == 1)
            {
                sign = i == '+';
            }
            else if (state == 2)
            {
                ans = ans * 10 + (i - '0');
                if (ans >= INT_MAX)
                {
                    state = 3;
                    break;
                }
            }
            else if (state == 3)
            {
                break;
            }
        }

        if (sign == false)
        {
            ans = -ans;
        }

        if (ans < INT_MIN)
        {
            return INT_MIN;
        }
        else if (ans > INT_MAX)
        {
            return INT_MAX;
        }
        else
        {
            return ans;
        }
    }
};
