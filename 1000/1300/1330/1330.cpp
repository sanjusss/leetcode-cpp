/*
 * @Author: sanjusss
 * @Date: 2023-05-12 08:47:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-12 10:56:34
 * @FilePath: \1000\1300\1330\1330.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int diff = 0;
        int maxS = INT_MIN;
        int minS = INT_MAX;
        for (int i = 1; i < n; ++i) {
            sum += abs(nums[i - 1] - nums[i]);
            if (i + 1 < n) {
                // [0, i]
                diff = max(diff, abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]));
            }
            // [i, n - 1]
            diff = max(diff, abs(nums[i - 1] - nums[n - 1]) - abs(nums[i - 1] - nums[i]));

            maxS = max(maxS, min(nums[i - 1], nums[i]));
            minS = min(minS, max(nums[i - 1], nums[i]));
        }

        diff = max(diff, 2 * (maxS - minS));
        return sum + diff;
    }
};

TEST(&Solution::maxValueAfterReverse)