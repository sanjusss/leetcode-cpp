/*
 * @Author: sanjusss
 * @Date: 2024-01-11 09:37:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-01-11 09:55:01
 * @FilePath: \2000\2600\2640\2645.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int addMinimum(string word) {
        int ans = 0;
        int cur = 0;
        for (char c : word) {
            int i = c - 'a';
            ans += (i + 3 - cur) % 3;
            cur = (i + 1) % 3;
        }

        if (cur != 0) {
            ans += 3 - cur;
        }

        return ans;
    }
};