/*
 * @Author: sanjusss
 * @Date: 2022-01-23 10:28:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-23 10:40:09
 * @FilePath: \C\C200\C270\C277\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int op = 0;
        int ne = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                while (nums[ne] > 0) {
                    ++ne;
                }

                ans[i] = nums[ne++];
            }
            else {
                while (nums[op] < 0) {
                    ++op;
                }

                ans[i] = nums[op++];
            }
        }

        return ans;
    }
};