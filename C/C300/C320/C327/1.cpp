/*
 * @Author: sanjusss
 * @Date: 2023-01-08 10:25:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-08 10:31:11
 * @FilePath: \C\C300\C320\C327\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p = 0;
        int n = 0;
        for (int i : nums) {
            if (i > 0) {
                ++p;
            }
            else if (i < 0) {
                ++n;
            }
        }

        return max(n, p);
    }
};