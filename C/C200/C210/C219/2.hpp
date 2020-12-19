/*
 * @Author: sanjusss
 * @Date: 2020-12-13 10:26:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-13 10:35:38
 * @FilePath: \C\C200\C210\C219\2.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char i : n) {
            ans = max(ans, i - '0');
        }

        return ans;
    }
};