/*
 * @Author: sanjusss
 * @Date: 2021-10-17 10:28:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-17 10:35:15
 * @FilePath: \C\C200\C260\C263\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0;
        int cur = 0;
        int n = s.size();
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                if (cur > 0) {
                    if (cur > prev) {
                        prev = cur;
                        cur = 0;
                    }
                    else {
                        return false;
                    }
                }
            }
            else if (isdigit(s[i])) {
                cur = cur * 10 + s[i] - '0';
            }
        }

        return true;
    }
};