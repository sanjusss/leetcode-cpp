/*
 * @Author: sanjusss
 * @Date: 2022-11-18 08:39:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-18 09:29:46
 * @FilePath: \0\800\890\891_20221118.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        static constexpr int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());

        int64_t ans = 0;
        int64_t minSum = 0;
        int64_t cnt = 0;
        for (int i : nums) {
            ans += cnt * i - minSum;
            ans %= mod;
            minSum += minSum + i;
            minSum %= mod;
            cnt += cnt + 1;
            cnt %= mod;
        }

        return ans;
    }
};