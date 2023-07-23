/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-23 10:40:15
 * @FilePath: \C\C300\C350\C355\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int64_t pre = 0;
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > pre) {
                pre = nums[i];
            }
            else {
                pre += nums[i];
            }
        }

        return pre;
    }
};