/*
 * @Author: sanjusss
 * @Date: 2022-07-27 08:24:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-27 08:50:29
 * @FilePath: \0\500\590\592.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string fractionAddition(string expression) {
        int64_t a = 0;
        int64_t b = 1;
        int64_t c = 0;
        int64_t d = 0;
        int n = expression.size();
        int64_t cur = 0;
        int64_t sign = 1;
        for (char i : expression) {
            if (i == '+' || i == '-') {
                if (cur != 0) {
                    d = cur * sign;
                    calc(a, b, c, d);
                    cur = 0;
                    sign = 1;
                }

                c = 0;
                d = 0;
                if (i == '-') {
                    sign *= -1;
                }
            }
            else if (i == '/') {
                c = cur * sign;
                cur = 0;
                sign = 1;
            }
            else {
                cur = cur * 10 + i - '0';
            }
        }

        d = cur * sign;
        calc(a, b, c, d);
        return to_string(a) + "/"s + to_string(b);
    }

private:
    void calc(int64_t& a, int64_t& b, int64_t c, int64_t d) {
        simple(c, d);
        int64_t m = lcm(b, d);
        a = a * (m / b) + c * (m / d);
        b = m;
        simple(a, b);
    }

    void simple(int64_t& a, int64_t& b) {
        if (a == 0) {
            b = 1;
            return;
        }

        if (b < 0) {
            b = -b;
            a = -a;
        }

        int d = gcd(abs(a), b);
        a /= d;
        b /= d;
    }
};

TEST(&Solution::fractionAddition)