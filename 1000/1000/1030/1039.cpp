/*
 * @Author: sanjusss
 * @Date: 2023-04-05 16:18:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-05 16:48:15
 * @FilePath: \1000\1000\1030\1039.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minScoreTriangulation(vector<int>& values) {
//         int n = values.size();
//         vector<vector<int>> sums(n, vector<int>(n));

//         function<int(int, int)> dp = [&] (int i, int j) -> int {
//             int& res = sums[i][j];
//             if (res != 0) {
//                 return res;
//             }

//             if (j - i < 2) {
//                 res = 0;
//             }
//             else if (j - i == 2) {
//                 res =  values[i] * values[i + 1] * values[j];
//             }
//             else {
//                 res = INT_MAX;
//                 for (int k = i + 1; k < j; ++k) {
//                     res = min(res, values[i] * values[j] * values[k] + dp(i, k) + dp(k, j));
//                 }
//             }

//             return res;
//         };

//         return dp(0, n - 1);
//     }
// };

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};