/*
 * @Author: sanjusss
 * @Date: 2022-12-26 08:39:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-26 08:44:01
 * @FilePath: \1000\1700\1750\1759.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countHomogenous(string s) {
        static constexpr int64_t mod = 1e9 + 7;
        int n = s.size();
        char prev = 0;
        int64_t cnt = 0;
        int64_t ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] != prev) {
                ans += (cnt + 1) * cnt / 2;
                ans %= mod;
                if (i < n) {
                    prev = s[i];
                    cnt = 1;
                }
            }
            else {
                ++cnt;
            }
        }

        return ans;
    }
};