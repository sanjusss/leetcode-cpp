/*
 * @Author: sanjusss
 * @Date: 2021-08-24 09:00:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-24 09:03:57
 * @FilePath: \jianzhioffer\64.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};