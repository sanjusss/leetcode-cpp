#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    string decodeString(string s) 
//    {
//        stack<pair<string, int>> parts;//{ 字符串，本层下一字符串需要重复次数 }
//        parts.push({ string(), 0 });
//        int length = s.length();
//        s += '\1';
//        for (int i = 0; i < length; ++i)
//        {
//            if (isalpha(s[i]))
//            {
//                int j = i + 1;
//                while (isalpha(s[j++]));
//                string t = s.substr(i, j - i - 1);
//
//                auto p = parts.top();
//                parts.pop();
//
//                p.first += t;
//                parts.push(p);
//                i = j - 1;
//            }
//
//            if (isdigit(s[i]))
//            {
//                int j = i + 1;
//                while (isdigit(s[j++]));
//                int num = stoi(s.substr(i, j - i - 1));
//                parts.push({ string(), num });
//                i = j - 1;
//            }
//
//            if (s[i] == ']')
//            {
//                auto prev1 = parts.top();
//                parts.pop();
//                auto prev2 = parts.top();
//                parts.pop();
//                for (int j = 0; j < prev1.second; ++j)
//                {
//                    prev2.first += prev1.first;
//                }
//
//                parts.push(prev2);
//            }
//        }
//
//        return parts.top().first;
//    }
//};

class Solution 
{
public:
    string decodeString(string s) 
    {
        stack<string> ts;
        stack<int> ns;
        ts.push(string());
        ns.push(1);
        int n = 0;
        for (char i : s)
        {
            if (i == '[')
            {
                ts.push(string());
                ns.push(n);
                n = 0;
            }
            else if (i == ']')
            {
                string temp = ts.top();
                ts.pop();
                for (int j = 0; j < ns.top(); ++j)
                {
                    ts.top() += temp;
                }

                ns.pop();
            }
            else if (isdigit(i))
            {
                n = n * 10 + i - '0';
            }
            else
            {
                ts.top() += i;
            }
        }

        return ts.top();
    }
};