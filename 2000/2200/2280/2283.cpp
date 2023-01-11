/*
 * @Author: sanjusss
 * @Date: 2023-01-11 08:33:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-11 08:36:01
 * @FilePath: \2000\2200\2280\2283.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        vector<int> cnt(n);
        for (char c : num) {
            if (c - '0' >= n) {
                return false;
            }
            
            ++cnt[c - '0'];
        }

        for (int i = 0; i < n; ++i) {
            if (cnt[i] != num[i] - '0') {
                return false;
            }
        }

        return true;
    }
};