/*
 * @Author: sanjusss
 * @Date: 2021-08-18 09:17:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-18 09:28:42
 * @FilePath: \jianzhioffer\58_20210818.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string reverseWords(string s) {
        char prev = ' ';
        int len = 0;
        for (char i : s) {
            if (i != ' ' || prev != ' ') {
                s[len++] = i;
            }

            prev = i;
        }

        if (len == 0) {
            return ""s;
        }

        if (s[len - 1] == ' ') {
            --len;
        }

        s.resize(len);

        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        reverse(s.begin() + start, s.end());
        return s;
    }
};