/*
 * @Author: sanjusss
 * @Date: 2022-12-16 08:29:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-16 08:31:38
 * @FilePath: \1000\1700\1780\1785.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int64_t sum = accumulate(nums.begin(), nums.end(), (int64_t)0);
        int64_t target = abs((int64_t)goal - sum);
        return (target + limit - 1) / limit;
    }
};