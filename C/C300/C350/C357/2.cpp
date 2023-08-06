/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-06 10:36:42
 * @FilePath: \C\C300\C350\C357\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2) {
            return true;
        }

        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] + nums[i] >= m) {
                return true;
            }
        }

        return false;
    }
};