/*
 * @Author: sanjusss
 * @Date: 2022-07-24 10:28:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-24 11:56:57
 * @FilePath: \C\C300\C300\C303\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> us(nums.begin(), nums.end());
        vector<int> cnt(64);
        for (int i : us) {
            ++cnt[__builtin_popcount(i)];
        }

        for (int i = 62; i >= 0; --i) {
            cnt[i] += cnt[i + 1];
        }

        int64_t ans = 0;
        for (int i : us) {
            int need = max(k - (int)__builtin_popcount(i), 0);
            ans += cnt[need];
        }

        return ans;
    }
};

TEST(&Solution::countExcellentPairs)