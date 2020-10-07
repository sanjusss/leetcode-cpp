/*
 * @Author: sanjusss
 * @Date: 2020-10-08 07:50:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-08 07:55:35
 * @FilePath: \0\300\340\344_20201008.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};