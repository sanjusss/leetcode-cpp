/*
 * @Author: sanjusss
 * @Date: 2022-05-29 10:27:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-29 10:32:35
 * @FilePath: \C\C200\C290\C295\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cnt(26);
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        vector<int> tc(26);
        for (char i : target) {
            ++tc[i - 'a'];
        }

        int ans = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (tc[i] > 0) {
                ans = min(ans, cnt[i] / tc[i]);
            }
        }

        return ans;
    }
};