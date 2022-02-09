/*
 * @Author: sanjusss
 * @Date: 2022-02-09 15:37:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-09 15:39:07
 * @FilePath: \0\100\180\186.cpp
 */
#include "leetcode.h"

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        int start = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
    }
};