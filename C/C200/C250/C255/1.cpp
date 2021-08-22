/*
 * @Author: sanjusss
 * @Date: 2021-08-22 10:29:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 10:32:33
 * @FilePath: \C\C200\C250\C255\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*min_element(nums.begin(), nums.end()), *max_element(nums.begin(), nums.end()));
    }
};