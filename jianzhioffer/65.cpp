/*
 * @Author: sanjusss
 * @Date: 2021-08-26 08:41:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-26 08:44:37
 * @FilePath: \jianzhioffer\65.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int r = (uint32_t)(a & b) << 1;
            a = a ^ b;
            b = r;
        }

        return a;
    }
};