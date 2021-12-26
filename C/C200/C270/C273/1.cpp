/*
 * @Author: sanjusss
 * @Date: 2021-12-26 10:24:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-26 10:32:52
 * @FilePath: \C\C200\C270\C273\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
};