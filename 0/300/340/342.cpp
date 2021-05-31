/*
 * @Author: sanjusss
 * @Date: 2021-05-31 08:45:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-31 08:46:27
 * @FilePath: \0\300\340\342.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & (n - 1)) && n % 3 == 1;
    }
};