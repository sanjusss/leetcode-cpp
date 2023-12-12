/*
 * @Author: sanjusss
 * @Date: 2023-12-12 15:37:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-12 15:37:15
 * @FilePath: \2000\2400\2450\2454.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        auto cmp = [&](int a, int b) {
            return nums[a] > nums[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q0(cmp);
        priority_queue<int, vector<int>, decltype(cmp)> q1(cmp);
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            while (!q1.empty() && nums[q1.top()] < nums[i]) {
                ans[q1.top()] = nums[i];
                q1.pop();
            }

            while (!q0.empty() && nums[q0.top()] < nums[i]) {
                q1.push(q0.top());
                q0.pop();
            }

            q0.push(i);
        }

        return ans;
    }
};