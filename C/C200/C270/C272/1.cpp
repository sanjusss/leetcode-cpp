/*
 * @Author: sanjusss
 * @Date: 2021-12-19 10:14:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-19 10:32:39
 * @FilePath: \C\C200\C270\C272\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const auto& s : words) {
            bool success = true;
            int left = 0;
            int right = s.size() - 1;
            while (left < right) {
                if (s[left++] != s[right--]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                return s;
            }
        }

        return {};
    }
};