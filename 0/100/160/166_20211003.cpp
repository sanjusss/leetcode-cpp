/*
 * @Author: sanjusss
 * @Date: 2021-10-03 09:19:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-03 09:40:08
 * @FilePath: \0\100\160\166_20211003.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int64_t n = numerator;
        int64_t d = denominator;
        string ans;
        if (n * d < 0) {
            ans = "-"s;
        }

        n = abs(n);
        d = abs(d);
        ans += to_string(n / d);
        int64_t r = n % d;
        if (r == 0) {
            return ans;
        }

        ans.push_back('.');
        string real;
        r = abs(r);
        unordered_map<int64_t, int> rs;
        for (int i = 0; r != 0; ++i) {
            if (rs.count(r)) {
                real.insert(rs[r], 1, '(');
                real.push_back(')');
                break;
            }

            rs[r] = i;
            r *= 10;
            real.push_back((char)(r / d) + '0');
            r %= d;
        }

        return ans + real;
    }
};

TEST(&Solution::fractionToDecimal)