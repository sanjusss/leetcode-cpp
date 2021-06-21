/*
 * @Author: sanjusss
 * @Date: 2021-06-20 10:31:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-20 10:33:22
 * @FilePath: \C\C200\C240\C247\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }

        return string();
    }
};