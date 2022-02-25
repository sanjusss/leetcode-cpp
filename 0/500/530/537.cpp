/*
 * @Author: sanjusss
 * @Date: 2022-02-25 08:21:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-25 08:30:04
 * @FilePath: \0\500\530\537.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto parse = [] (const string& s, int& a, int& b) {
            auto add = s.find('+');
            a = stoi(s.substr(0, add));
            b = stoi(s.substr(add + 1, s.size() - add - 2));
        };

        int a;
        int b;
        parse(num1, a, b);
        int c;
        int d;
        parse(num2, c, d);

        int r = a * c - b * d;
        int v = a * d + b * c;
        return to_string(r) + '+' + to_string(v) + 'i';
    }
};