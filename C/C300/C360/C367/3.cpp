/*
 * @Author: sanjusss
 * @Date: 2023-10-15 10:48:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-15 10:55:48
 * @FilePath: \C\C300\C360\C367\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        int minV = INT_MAX;
        int minI = -1;
        int maxV = INT_MIN;
        int maxI = -1;
        for (int i = indexDifference; i < n; ++i) {
            if (nums[i - indexDifference] <= minV) {
                minV = nums[i - indexDifference];
                minI = i - indexDifference;
            }

            if (nums[i - indexDifference] >= maxV) {
                maxV = nums[i - indexDifference];
                maxI = i - indexDifference;
            }

            if (abs(nums[i] - minV) >= valueDifference) {
                return {{ minI, i }};
            }

            if (abs(nums[i] - maxV) >= valueDifference) {
                return {{ maxI, i }};
            }
        }

        return {{ -1, -1 }};
    }
};