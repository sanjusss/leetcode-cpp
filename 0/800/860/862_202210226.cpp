/*
 * @Author: sanjusss
 * @Date: 2022-10-26 09:11:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-26 09:46:52
 * @FilePath: \0\800\860\862_202210226.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int64_t> sums(n + 1);
//         for (int i = 0; i < n; ++i) {
//             sums[i + 1] = sums[i] + nums[i];
//         }

//         int ans = INT_MAX;
//         vector<pair<int64_t, int>> s;
//         s.emplace_back(0, 0);
//         for (int i = 1; i <= n; ++i) {
//             auto p = upper_bound(s.begin(), s.end(), sums[i] - k, [] (int64_t a, const pair<int64_t, int>& b) {
//                 return a < b.first;
//             });
//             if (p != s.begin()) {
//                 ans = min(ans, i - prev(p)->second);
//             }
            
//             while (!s.empty() && s.back().first >= sums[i]) {
//                 s.pop_back();
//             }

//             s.emplace_back(sums[i], i);
//         }

//         return ans == INT_MAX ? -1 : ans;
//     }
// };

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int64_t> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        int ans = INT_MAX;
        deque<pair<int64_t, int>> q;
        q.emplace_back(0, 0);
        for (int i = 1; i <= n; ++i) {
            while (!q.empty() && q.front().first + k <= sums[i]) {
                ans = min(ans, i - q.front().second);
                q.pop_front();
            }

            while (!q.empty() && q.back().first >= sums[i]) {
                q.pop_back();
            }

            q.emplace_back(sums[i], i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

TEST(&Solution::shortestSubarray)