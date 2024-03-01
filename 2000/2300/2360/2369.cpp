/*
 * @Author: sanjusss
 * @Date: 2024-03-01 09:43:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-03-01 10:00:05
 * @FilePath: \2000\2300\2360\2369.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        bool pre3 = true;
        bool pre2 = true;
        bool pre1 = false;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            bool cur = false;
            if (nums[i] == nums[i - 1]) {
                cur = cur || pre2;
            }

            if (i >= 2) {
                if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                    cur = cur || pre3;
                }

                if (nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) {
                    cur = cur || pre3;
                }
            }

            pre3 = pre2;
            pre2 = pre1;
            pre1 = cur;
        }

        return pre1;
    }
};