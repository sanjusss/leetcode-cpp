/*
 * @Author: sanjusss
 * @Date: 2022-01-22 14:09:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-22 14:46:14
 * @FilePath: \1000\1300\1330\1332.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int removePalindromeSub(string s) {
        if (equal(s.begin(), s.end(), s.rbegin(), s.rend())) {
            return 1;
        }
        else {
            return 2;
        }
    }
};