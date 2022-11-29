/*
 * @Author: sanjusss
 * @Date: 2022-11-29 08:53:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-29 08:55:36
 * @FilePath: \1000\1700\1750\1758.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                cnt1 += s[i] - '0';
                cnt2 += '1' - s[i];
            }
            else {
                cnt2 += s[i] - '0';
                cnt1 += '1' - s[i];
            }
        }

        return min(cnt1, cnt2);
    }
};