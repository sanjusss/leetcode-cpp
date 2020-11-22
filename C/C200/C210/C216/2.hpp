/*
 * @Author: sanjusss
 * @Date: 2020-11-22 10:36:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-22 10:43:33
 * @FilePath: \C\C200\C210\C216\2.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        int i = n - 1;
        while (k > 0) {
            if (k > 25) {
                k -= 25;
                ans[i--] = 'z';
            }
            else {
                ans[i] = 'a' + k;
                break;
            }
        }

        return ans;
    }
};