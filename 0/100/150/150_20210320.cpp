/*
 * @Author: sanjusss
 * @Date: 2021-03-20 18:53:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-20 18:57:13
 * @FilePath: \0\100\150\150_20210320.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string& i : tokens) {
            if (i == "+") {
                int b = s.top();
                s.pop();
                s.top() += b;
            }
            else if (i == "-") {
                int b = s.top();
                s.pop();
                s.top() -= b;
            }
            else if (i == "*") {
                int b = s.top();
                s.pop();
                s.top() *= b;
            }
            else if (i == "/") {
                int b = s.top();
                s.pop();
                s.top() /= b;
            }
            else {
                s.push(stoi(i));
            }
        }

        return s.top();
    }
};

TEST(&Solution::evalRPN)