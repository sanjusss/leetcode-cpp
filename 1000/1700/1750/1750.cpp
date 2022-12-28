/*
 * @Author: sanjusss
 * @Date: 2022-12-28 08:22:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-28 08:25:17
 * @FilePath: \1000\1700\1750\1750.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                break;
            }

            ++left;
            while (left< right && s[left - 1] == s[left]) {
                ++left;
            }

            --right;
            while (left < right && s[right] == s[right + 1]) {
                --right;
            }
        }

        return max(0, right - left + 1);
    }
};