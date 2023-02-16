/*
 * @Author: sanjusss
 * @Date: 2023-02-16 08:49:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-16 08:53:09
 * @FilePath: \2000\2300\2340\2341.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        vector<int> ans(2);
        for (auto [_, c] : cnt) {
            ans[0] += c / 2;
            ans[1] += c % 2;
        }

        return ans;
    }
};