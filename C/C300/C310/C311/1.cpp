/*
 * @Author: sanjusss
 * @Date: 2022-09-18 10:28:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-18 10:30:38
 * @FilePath: \C\C300\C310\C311\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : n * 2;
    }
};