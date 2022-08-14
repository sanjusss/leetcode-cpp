/*
 * @Author: sanjusss
 * @Date: 2022-08-14 08:18:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-14 08:21:45
 * @FilePath: \1000\1400\1420\1422.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0;
        int zeros = 0;
        int ans = 0;
        for (char i : s) {
            if (i == '1') {
                ++ones;
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0') {
                ++zeros;
            }
            else {
                --ones;
            }

            ans = max(ans, ones + zeros);
        }

        return ans;
    }
};