/*
 * @Author: sanjusss
 * @Date: 2022-07-17 10:28:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-17 10:32:19
 * @FilePath: \C\C300\C300\C302\1.cpp
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