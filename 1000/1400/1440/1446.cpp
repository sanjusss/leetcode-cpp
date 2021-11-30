/*
 * @Author: sanjusss
 * @Date: 2021-12-01 07:51:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-01 07:52:53
 * @FilePath: \1000\1400\1440\1446.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        int cnt = 0;
        char prev = 0;
        for (char i : s) {
            if (i == prev) {
                ++cnt;
            }
            else {
                prev = i;
                cnt = 1;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};