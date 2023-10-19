/*
 * @Author: sanjusss
 * @Date: 2023-10-19 13:53:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-19 13:59:19
 * @FilePath: \1000\1700\1720\1726.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++cnt[nums[i] * nums[j]];
            }
        }

        int ans = 0;
        for (auto [_, c] : cnt) {
            ans += c * (c - 1) * 4;
        }

        return ans;
    }
};