/*
 * @Author: sanjusss
 * @Date: 2021-07-01 07:53:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-01 08:07:05
 * @FilePath: \D\D000\D55\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int64_t even = nums.front();
        int64_t odd = 0;
        for (int i : nums) {
            tie(even, odd) = make_pair(max(even, odd + i), max(odd, even - i));
        }

        return max(even, odd);
    }
};

TEST(&Solution::maxAlternatingSum)