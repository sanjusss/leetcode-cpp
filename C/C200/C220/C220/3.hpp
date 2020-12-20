/*
 * @Author: sanjusss
 * @Date: 2020-12-20 11:00:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-20 11:24:06
 * @FilePath: \C\C200\C220\C220\3.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dp(n, INT_MIN);
//         dp[0] = nums[0];
//         for (int i = 1; i < n; ++i) {
//             for (int j = max(0, i - k); j < i; ++j) {
//                 dp[i] = max(dp[i], dp[j] + nums[i]);
//             }
//         }

//         return dp[n - 1];
//     }
// };

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[0];
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            else {
                return a.first < b.first;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        q.emplace(ans, 0);
        for (int i = 1; i < n; ++i) {
            int minPos = max(0, i - k);
            while (q.top().second < minPos) {
                q.pop();
            }

            ans = q.top().first + nums[i];
            q.emplace(ans, i);
        }

        return ans;
    }
};