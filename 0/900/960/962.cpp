/*
 * @Author: sanjusss
 * @Date: 2022-10-29 09:22:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-29 09:54:31
 * @FilePath: \0\900\960\962.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         vector<int> q; // 从大到小
//         int n = nums.size();
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             auto p = lower_bound(q.begin(), q.end(), i, [&nums](int a, int b) {
//                 return nums[a] > nums[b];
//             });
//             if (p != q.end()) {
//                 ans = max(ans, i - *p);
//             }

//             if (q.empty() || nums[q.back()] > nums[i]) {
//                 q.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s; // 从大到小
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }

        int ans = 0;
        for (int i = n - 1; i >= ans; --i) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                ans = max(ans, i - s.top());
                s.pop();
            }
        }

        return ans;
    }
};

TEST(&Solution::maxWidthRamp)