/*
 * @Author: sanjusss
 * @Date: 2023-07-20 08:18:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-20 09:19:49
 * @FilePath: \0\900\910\918.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int n = nums.size();
//         deque<pair<int, int>> q;
//         int cur = 0;
//         for (int i = 0; i < n; ++i) {
//             cur += nums[i];
//             while (!q.empty() && q.back().first >= cur) {
//                 q.pop_back();
//             }

//             q.emplace_back(cur, i == n - 1 ? n : i);
//         }

//         int ans = INT_MIN;
//         for (int i = 0; i < n; ++i) {
//             if (!q.empty() && q.front().second == i) {
//                 q.pop_front();
//             }

//             cur += nums[i];
//             ans = max(ans, cur - q.front().first);

//             while (!q.empty() && q.back().first >= cur) {
//                 q.pop_back();
//             }

//             q.emplace_back(cur, i);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int maxSub = INT_MIN;
        int preMax = 0;
        int minSub = 0;
        int preMin = 0;
        for (int i = 0; i < n; ++i) {
            total += nums[i];

            preMax = max(preMax + nums[i], nums[i]);
            maxSub = max(preMax, maxSub);

            preMin = min(preMin + nums[i], nums[i]);
            minSub = min(preMin, minSub);
        }

        if (minSub == total) {
            return maxSub;
        }
        else {
            return max(maxSub, total - minSub);
        }
    }
};

TEST(&Solution::maxSubarraySumCircular)