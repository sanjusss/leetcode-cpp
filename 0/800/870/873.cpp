/*
 * @Author: sanjusss
 * @Date: 2022-07-09 09:08:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-09 09:59:05
 * @FilePath: \0\800\870\873.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int ans = 0;
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int>(n));
//         for (int i = n - 1; i >= 0; --i) {
//             for (int j = i + 1; j < n; ++j) {
//                 auto p = lower_bound(arr.begin() + j + 1, arr.end(), arr[i] + arr[j]);
//                 if (p == arr.end() || *p != arr[i] + arr[j]) {
//                     dp[i][j] = 2;
//                     continue;
//                 }

//                 int k = p - arr.begin();
//                 dp[i][j] = 1 + dp[j][k];
//                 ans = max(ans, dp[i][j]);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (!pos.count(arr[i] + arr[j])) {
                    dp[i][j] = 2;
                    continue;
                }

                dp[i][j] = 1 + dp[j][pos[arr[i] + arr[j]]];
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};

TEST(&Solution::lenLongestFibSubseq)