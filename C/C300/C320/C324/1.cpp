/*
 * @Author: sanjusss
 * @Date: 2022-12-18 10:24:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-18 10:33:18
 * @FilePath: \C\C300\C320\C324\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> cnt;
        for (auto& s : words) {
            int v = 0;
            for (char c : s) {
                v |= 1 << (c - 'a');
            }

            ++cnt[v];
        }

        int ans = 0;
        for (auto [_, c] : cnt) {
            ans += c * (c - 1) / 2;
        }

        return ans;
    }
};