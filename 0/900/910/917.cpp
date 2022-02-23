/*
 * @Author: sanjusss
 * @Date: 2022-02-23 08:21:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-23 08:25:10
 * @FilePath: \0\900\910\917.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalpha(s[left])) {
                ++left;
            }

            while (left < right && !isalpha(s[right])) {
                --right;
            }

            if (left < right) {
                swap(s[left++], s[right--]);
            }
        }

        return s;
    }
};

TEST(&Solution::reverseOnlyLetters)