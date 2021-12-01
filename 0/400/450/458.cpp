/*
 * @Author: sanjusss
 * @Date: 2021-12-01 07:58:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-01 07:59:23
 * @FilePath: \0\400\450\458.cpp
 */
#include "leetcode.h"


class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(base));
    }
};