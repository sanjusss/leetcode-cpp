/*
 * @Author: sanjusss
 * @Date: 2021-11-30 13:32:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-30 14:35:56
 * @FilePath: \0\400\400\400.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }

        int64_t end = 10;
        int64_t size = 1;
        int64_t p = 10;
        while (true) {
            ++size;
            if (p + end * 9 * size <= n) {
                p += end * 9 * size;
                end *= 10;
                continue;
            }

            int number = (n - p) / size + end;
            for (int i = size - (n - p) % size - 1; i > 0; --i) {
                number /= 10;
            }

            return number % 10;
        }

        return 0;
    }
};

TEST(&Solution::findNthDigit)