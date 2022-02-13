/*
 * @Author: sanjusss
 * @Date: 2022-02-13 09:29:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-13 09:34:04
 * @FilePath: \1000\1100\1180\1189.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26);
        for (char i : text) {
            ++cnt[i - 'a'];
        }

        string pattern = "balloon";
        unordered_map<int, int> factors;
        for (char i : pattern) {
            ++factors[i - 'a'];
        }

        int ans = INT_MAX;
        for (auto [i, c] : factors) {
            ans = min(ans, cnt[i] / c);
        }

        return ans;
    }
};