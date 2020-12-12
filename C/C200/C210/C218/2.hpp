/*
 * @Author: sanjusss
 * @Date: 2020-12-06 10:42:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-06 10:49:24
 * @FilePath: \C\C200\C210\C218\2.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        int ans = 0;
        for (auto& p : cnt) {
            if (p.second == 0) {
                continue;
            }

            if (p.first + p.first == k) {
                int t = p.second / 2;
                p.second -= t * 2;
                ans += t;
                continue;
            }

            auto pos = cnt.find(k - p.first);
            if (pos != cnt.end()) {
                int t = min(pos->second, p.second);
                pos->second -= t;
                p.second -= t;
                ans += t;
            }
        }

        return ans;
    }
};