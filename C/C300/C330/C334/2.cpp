/*
 * @Author: sanjusss
 * @Date: 2023-02-19 10:29:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-26 10:37:07
 * @FilePath: \C\C300\C330\C334\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        int64_t r = 0;
        for (char c : word) {
            int64_t i = c - '0';
            r = (r * 10 + i) % m;
            ans.push_back(r == 0 ? 1 : 0);
        }

        return ans;
    }
};