/*
 * @Author: sanjusss
 * @Date: 2021-09-19 10:35:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-19 10:46:38
 * @FilePath: \C\C200\C250\C259\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        stack<int> rights;
        for (int i = n - 1; i > 0; --i) {
            if (rights.empty() || rights.top() >= nums[i]) {
                rights.push(nums[i]);
            }
        }

        int ans = 0;
        int left = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == rights.top()) {
                rights.pop();
            }

            if (nums[i] > left && nums[i] < rights.top()) {
                ans += 2;
            }
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                ++ans;
            }

            left = max(left, nums[i]);
        }

        return ans;
    }
};

TEST(&Solution::sumOfBeauties)