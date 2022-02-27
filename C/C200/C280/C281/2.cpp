/*
 * @Author: sanjusss
 * @Date: 2022-02-27 10:39:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-27 10:40:28
 * @FilePath: \C\C200\C280\C281\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt(26);
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        for (char i : t) {
            --cnt[i - 'a'];
        }

        int ans = 0;
        for (int i : cnt) {
            ans += abs(i);
        }

        return ans;
    }
};