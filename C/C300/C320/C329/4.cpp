/*
 * @Author: sanjusss
 * @Date: 2023-01-22 11:06:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-22 11:19:28
 * @FilePath: \C\C300\C320\C329\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minCost(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<unordered_map<int, int>> cnt(n + 1);
//         vector<int> dp(n + 1);
//         for (int i = 0; i < n; ++i) {
//             auto& cur = cnt[i + 1];
//             cur = cnt[i];
//             cur[nums[i]] += 1;
//             dp[i + 1] = INT_MAX / 2;
//             for (int j = 0; j <= i; ++j) {
//                 auto& prev = cnt[j];
//                 int len = 0;
//                 for (auto [k, c] : cur) {
//                     int l = prev.count(k) ? c - prev[k] : c;
//                     if (l > 1) {
//                         len += l;
//                     }
//                 }

//                 dp[i + 1] = min(dp[i + 1], dp[j] + k + len);
//             }
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> cnt;
            int len = 0;
            dp[i + 1] = INT_MAX / 2;
            for (int j = i; j >= 0; --j) {
                switch (++cnt[nums[j]]) {
                    case 1:
                        break;

                    case 2:
                        len += 2;
                        break;

                    default:
                        ++len;
                        break;
                }

                dp[i + 1] = min(dp[i + 1], dp[j] + k + len);
            }
        }

        return dp[n];
    }
};