/*
 * @Author: sanjusss
 * @Date: 2021-10-10 10:16:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-10 10:21:29
 * @FilePath: \0\400\440\441.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int arrangeCoins(int n) {
        int64_t left = 0;
        int64_t right = INT_MAX;
        while (left < right) {
            int64_t mid = (left + right) / 2;
            if (mid * (mid + 1) / 2 <= n) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left - 1;
    }
};