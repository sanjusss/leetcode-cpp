/*
 * @Author: sanjusss
 * @Date: 2021-09-01 08:19:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-01 08:28:33
 * @FilePath: \jianzhioffer\59.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }

            q.push_back(i);
            if (i < k - 1) {
                continue;
            }

            while (q.front() < i - k + 1) {
                q.pop_front();
            }

            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};