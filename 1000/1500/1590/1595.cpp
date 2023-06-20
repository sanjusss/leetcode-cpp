/*
 * @Author: sanjusss
 * @Date: 2023-06-20 09:06:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-20 09:36:24
 * @FilePath: \1000\1500\1590\1595.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int connectTwoGroups(vector<vector<int>>& cost) {
//         int size1 = cost.size();
//         int size2 = cost[0].size();

//         unordered_map<int, int> dp;
//         queue<int> q;
//         q.emplace(0);
//         while (!q.empty()) {
//             int mask = q.front();
//             q.pop();
//             int cur = dp[mask];
//             for (int i = 0; i < size1; ++i) {
//                 if (mask & (1 << i)) {
//                     continue;
//                 }

//                 for (int j = 0; j < size2; ++j) {
//                     int nmask = mask | (1 << (size1 + j)) | (1 << i);
//                     int next = cur + cost[i][j];
//                     if (dp.count(nmask)) {
//                         dp[nmask] = min(dp[nmask], next);
//                     }
//                     else {
//                         dp[nmask] = next;
//                         q.emplace(nmask);
//                     }
//                 }
//             }

//             for (int j = 0; j < size2; ++j) {
//                 if (mask & (1 << (size1 + j))) {
//                     continue;
//                 }

//                 for (int i = 0; i < size1; ++i) {
//                     int nmask = mask | (1 << (size1 + j)) | (1 << i);
//                     int next = cur + cost[i][j];
//                     if (dp.count(nmask)) {
//                         dp[nmask] = min(dp[nmask], next);
//                     }
//                     else {
//                         dp[nmask] = next;
//                         q.emplace(nmask);
//                     }
//                 }
//             }
//         }

//         return dp[(1 << (size1 + size2)) - 1];
//     }
// };

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost[0].size();

        vector<int> cur(1 << n, INT_MAX / 2);
        cur[0] = 0;
        vector<int> pre(1 << n);
        vector<int> minCost(n, INT_MAX);
        for (auto& c : cost) {
            swap(cur, pre);
            fill(cur.begin(), cur.end(), INT_MAX / 2);
            for (int mask = (1 << n) - 1; mask >= 0; --mask) {
                for (int i = 0; i < n; ++i) {
                    int nextMask = mask | (1 << i);
                    cur[nextMask] = min(cur[nextMask], pre[mask] + c[i]);
                }
            }

            for (int i = 0; i < n; ++i) {
                minCost[i] = min(minCost[i], c[i]);
            }
        }

        int ans = INT_MAX;
        for (int mask = (1 << n) - 1; mask >= 0; --mask) {
            int sum = cur[mask];
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    continue;
                }

                sum += minCost[i];
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};