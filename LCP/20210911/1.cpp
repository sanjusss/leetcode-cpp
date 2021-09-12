/*
 * @Author: sanjusss
 * @Date: 2021-09-11 15:05:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-11 15:09:39
 * @FilePath: \LCP\20210911\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        unordered_map<int, int> cnt;
        for (auto& row : source) {
            for (int i : row) {
                ++cnt[i];
            }
        }

        for (auto& row : target) {
            for (int i : row) {
                --cnt[i];
            }
        }

        int ans = 0;
        for (auto [_, i] : cnt) {
            ans += abs(i);
        }

        return ans / 2;
    }
};