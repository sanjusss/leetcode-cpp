/*
 * @Author: sanjusss
 * @Date: 2023-09-01 08:54:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-01 08:56:17
 * @FilePath: \2000\2200\2240\2240.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for (int c1 = 0; c1 * cost1 <= total; ++c1) {
            ans += (total - c1 * cost1) / cost2 + 1;
        }

        return ans;
    }
};