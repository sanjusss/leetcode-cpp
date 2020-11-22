/*
 * @Author: sanjusss
 * @Date: 2020-10-11 10:30:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-11 10:33:43
 * @FilePath: \C\C200\C200\C210\1.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
   public:
    int maxDepth(string s) {
        int ans = 0;
        int left = 0;
        for (char i : s) {
            switch (i) {
                case '(':
                    ++left;
                    ans = max(left, ans);
                    break;

                case ')':
                    --left;
                    break;

                default:
                    break;
            }
        }

        return ans;
    }
};