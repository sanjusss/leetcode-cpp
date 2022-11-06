/*
 * @Author: sanjusss
 * @Date: 2022-11-06 10:30:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-06 10:33:43
 * @FilePath: \C\C300\C310\C318\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[cnt++] = nums[i];
            }
        }

        for (int i = cnt; i < n; ++i) {
            nums[i] = 0;
        }

        return nums;
    }
};