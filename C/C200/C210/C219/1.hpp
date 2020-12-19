/*
 * @Author: sanjusss
 * @Date: 2020-12-13 10:26:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-13 10:32:23
 * @FilePath: \C\C200\C210\C219\1.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 1) {
            ans += n / 2;
            n = (n + 1) / 2;
        }

        return ans;
    }
};