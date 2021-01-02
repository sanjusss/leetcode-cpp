#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<pair<int, int>> q;
//         vector<int> ans;
//         for (int i = 0; i < nums.size(); ++i) {
//             while (!q.empty() && q.front().first <= i - k) {
//                 q.pop_front();
//             }

//             while (!q.empty() && q.back().second <= nums[i]) {
//                 q.pop_back();
//             }

//             q.emplace_back(i, nums[i]);
//             if (i >= k - 1) {
//                 ans.push_back(q.front().second);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }

            q.emplace_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }

        return ans;
    }
};