/*
 * @Author: sanjusss
 * @Date: 2023-07-11 09:05:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-11 09:21:52
 * @FilePath: \1000\1900\1910\1911.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int64_t odd = 0;
        int64_t even = INT_MIN;
        for (int i : nums) {
            tie(odd, even) = make_pair(max<int64_t>(odd, even - i), max<int64_t>(even, odd + i));
        }

        return max(odd, even);
    }
};