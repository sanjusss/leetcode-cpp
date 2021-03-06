/*
 * @Author: sanjusss
 * @Date: 2021-03-06 18:22:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-06 18:28:24
 * @FilePath: \0\500\500\503.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        if (n == 0) {
            return ans;
        }

        stack<int> s;
        int maxValue = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                ans[s.top()] = nums[i];
                s.pop();
            }

            if (nums[i] == maxValue) {
                ans[i] = -1;
            }
            else {
                s.push(i);
            }
        }

        for (int i = 0; i < n && !s.empty(); ++i) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                ans[s.top()] = nums[i];
                s.pop();
            }
        }

        return ans;
    }
};

TEST(&Solution::nextGreaterElements)