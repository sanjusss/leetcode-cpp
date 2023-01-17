/*
 * @Author: sanjusss
 * @Date: 2023-01-17 08:04:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-17 08:07:04
 * @FilePath: \1000\1800\1810\1814.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            int j = i;
            int r = 0;
            while (j > 0) {
                r = r * 10 + j % 10;
                j /= 10;
            }

            ++cnt[i - r];
        }

        static constexpr int64_t mod = 1e9 + 7;
        int64_t ans = 0;
        for (auto [_, c] : cnt) {
            ans += (int64_t)c * (int64_t)(c - 1) / 2;
            ans %= mod;
        }

        return ans;
    }
};