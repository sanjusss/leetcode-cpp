/*
 * @Author: sanjusss
 * @Date: 2023-06-01 10:23:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-01 13:46:34
 * @FilePath: \1000\1100\1130\1130.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int mctFromLeafValues(vector<int>& arr) {
//         int n = arr.size();
//         vector<vector<int>> maxV(n, vector<int>(n));
//         vector<vector<int64_t>> dp(n, vector<int64_t>(n, INT32_MAX));
//         for (int i = n - 1; i >= 0; --i) {
//             maxV[i][i] = arr[i];
//             dp[i][i] = 0;
//             for (int j = i + 1; j < n; ++j) {
//                 maxV[i][j] = max(arr[j], maxV[i][j - 1]);
//                 // [i, k], [k + 1, j]
//                 for (int k = i; k < j; ++k) {
//                     dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxV[i][k] * maxV[k + 1][j]);
//                 }
//             }
//         }

//         return dp[0][n - 1];
//     }
// };

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        stack<int> s;
        for (int i : arr) {
            while (!s.empty() && s.top() <= i) {
                int b = s.top();
                s.pop();
                if (s.empty() || s.top() > i) {
                    ans += b * i;
                }
                else {
                    ans += s.top() *  b;
                }
            }

            s.push(i);
        }

        while (s.size() >= 2) {
            int a = s.top();
            s.pop();
            ans += a * s.top();
        }

        return ans;
    }
};