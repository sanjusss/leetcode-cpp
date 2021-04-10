/*
 * @Author: sanjusss
 * @Date: 2021-04-10 10:12:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-10 10:15:03
 * @FilePath: \0\200\260\263.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }

        while (n % 2 == 0) {
            n /= 2;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        while (n % 5 == 0) {
            n /= 5;
        }

        return n == 1;
    }
};

TEST(&Solution::isUgly)