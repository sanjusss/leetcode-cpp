/*
 * @Author: sanjusss
 * @Date: 2022-02-13 09:41:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-13 09:46:19
 * @FilePath: \0\200\250\258.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int next = 0;
            while (num > 0) {
                next += num % 10;
                num /= 10;
            }

            num = next;
        }

        return num;
    }
};