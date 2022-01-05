/*
 * @Author: sanjusss
 * @Date: 2022-01-05 07:59:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-05 08:12:49
 * @FilePath: \1000\1500\1570\1576.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        int left = -1;
        for (int i = 0; i <= n; ++i) {
            if (i < n && s[i] == '?') {
                continue;
            }

            if (i - left - 1 == 0) {
                left = i;
                continue;
            }

            char a = 'a';
            while ((left > 0 && (a == s[left] || a + 1 == s[left])) || (i < n && (a == s[i] || a + 1 == s[i]))) {
                ++a;
            }

            bool add = false;
            for (int j = left + 1; j < i; ++j) {
                s[j] = a + (add ? 1 : 0);
                add = !add;
            }

            left = i;
        }

        return s;
    }
};