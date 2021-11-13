/*
 * @Author: sanjusss
 * @Date: 2021-11-13 15:51:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-13 16:07:04
 * @FilePath: \0\500\520\520.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n <= 1) {
            return true;
        }

        bool firstLower = word[0] >= 'a' && word[0] <= 'z';
        bool secondLower = word[1] >= 'a' && word[1] <= 'z';
        if (firstLower && !secondLower) {
            return false;
        }

        for (int i = 2; i < n; ++i) {
            if ((word[i] >= 'a' && word[i] <= 'z') != secondLower) {
                return false;
            }
        }

        return true;
    }
};