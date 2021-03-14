/*
 * @Author: sanjusss
 * @Date: 2021-03-14 10:34:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-14 10:41:54
 * @FilePath: \C\C200\C230\C232\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> diff;
        for (int i = 0; i < n && diff.size() <= 2; ++i) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        if (diff.size() > 2 || diff.size() == 1) {
            return false;
        }
        else if (diff.empty()) {
            return true;
        }
        else {
            return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
        }
    }
};