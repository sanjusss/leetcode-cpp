/*
 * @Author: sanjusss
 * @Date: 2021-05-29 22:03:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-29 22:32:36
 * @FilePath: \D\D000\D57\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) {
                ++ans;
            }
        }

        return ans;
    }
};