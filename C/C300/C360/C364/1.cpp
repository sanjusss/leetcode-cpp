/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-24 10:32:48
 * @FilePath: \C\C300\C360\C364\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '1') {
                ++cnt;
            }
        }

        --cnt;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i < cnt || i == n - 1) {
                s[i] = '1';
            }
            else {
                s[i] = '0';
            }
        }

        return s;
    }
};