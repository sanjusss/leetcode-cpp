/*
 * @Author: sanjusss
 * @Date: 2021-09-05 10:31:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-05 10:35:23
 * @FilePath: \C\C200\C250\C257\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    for (int l = k + 1; l < n; ++l) {
                        if (nums[i] + nums[j] + nums[k] == nums[l]) {
                            ++ans;
                        }
                    }
                }
            }
        }

        return ans;
    }
};