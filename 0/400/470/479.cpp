/*
 * @Author: sanjusss
 * @Date: 2022-04-16 10:46:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-16 10:51:42
 * @FilePath: \0\400\470\479.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }

        int64_t high = (int)pow(10, n) - 1;
        for (int64_t left = high; ; --left) {
            int64_t v = left;
            for (int64_t i = left; i > 0; i /= 10) {
                v *= 10;
                v += i % 10;
            }

            for (int64_t j = high; j * j >= v; --j) {
                if (v % j == 0) {
                    return v % 1337;
                }
            }
        }

        return 0;
    }
};