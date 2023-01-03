/*
 * @Author: sanjusss
 * @Date: 2023-01-03 08:35:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-03 08:39:54
 * @FilePath: \2000\2000\2040\2042.cpp
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
                if (cur == 0) {
                    continue;
                }
                else if (cur <= prev) {
                    return false;
                }

                prev = cur;
                cur = 0;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                cur = cur  * 10 + s[i] - '0';
            }
        }

        return true;
    }
};