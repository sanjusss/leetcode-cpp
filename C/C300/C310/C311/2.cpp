/*
 * @Author: sanjusss
 * @Date: 2022-09-18 10:28:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-18 10:35:11
 * @FilePath: \C\C300\C310\C311\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0;
        int n = s.size();
        int i = 0;
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && s[i] + 1 == s[i + 1]) {
                ++i;
                ++cnt;
            }

            ++i;
            ans = max(cnt, ans);
        }

        return ans;
    }
};