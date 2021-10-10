/*
 * @Author: sanjusss
 * @Date: 2021-10-03 10:32:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-03 10:33:59
 * @FilePath: \C\C200\C260\C261\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'X') {
                ++ans;
                i += 2;
            }
        }

        return ans;
    }
};