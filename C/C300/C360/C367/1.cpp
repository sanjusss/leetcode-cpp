/*
 * @Author: sanjusss
 * @Date: 2023-10-15 10:31:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-15 10:36:12
 * @FilePath: \C\C300\C360\C367\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference) {
                    return { { i, j } };
                }
            }
        }

        return {{ -1, -1 }};
    }
};