/*
 * @Author: sanjusss
 * @Date: 2022-04-17 10:28:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-17 10:39:29
 * @FilePath: \C\C200\C280\C289\2.cpp
 */

#include "leetcode.h"

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (int i : tasks) {
            ++cnt[i];
        }

        int ans = 0;
        for (auto [_, c] : cnt) {
            if (c == 1) {
                return -1;
            }
            else if (c % 3 == 0) {
                ans += c / 3;
            }
            else {
                ans += c / 3 + 1;
            }
        }

        return ans;
    }
};