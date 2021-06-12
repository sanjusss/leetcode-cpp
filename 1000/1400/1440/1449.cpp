/*
 * @Author: sanjusss
 * @Date: 2021-06-12 10:09:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-12 11:17:55
 * @FilePath: \1000\1400\1440\1449.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string largestNumber(vector<int>& cost, int target) {
//         vector<vector<int>> dp(target + 1, vector<int>(10));
//         for (int i = 1; i <= target; ++i) {
//             dp[i][9] = INT_MIN;
//         }

//         auto isBigger = [](const vector<int>& a, const vector<int>& b) {
//             for (int i = 9; i >= 0; --i) {
//                 if (a[i] != b[i]) {
//                     return a[i] > b[i];
//                 }
//             }

//             return false;
//         };
//         for (int i = 0; i < 9; ++i) {
//             int c = cost[i];
//             vector<int> next;
//             for (int j = c; j <= target; ++j) {
//                 next = dp[j - c];
//                 ++next[9];
//                 ++next[i];
//                 if (isBigger(next, dp[j])) {
//                     dp[j] = next;
//                 }
//             }
//         }

//         if (dp[target][9] <= 0) {
//             return "0"s;
//         }
//         else {
//             string ans;
//             ans.reserve(dp[target][9]);
//             for (int i = 8; i >= 0; --i) {
//                 for (int j = dp[target][i]; j > 0; --j) {
//                     ans.push_back('0' + 1 + i);
//                 }
//             }

//             return ans;
//         }
//     }
// };

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int i = 0; i <= 8; ++i) {
            int c = cost[i];
            for (int j = c; j <= target; ++j) {
                dp[j] = max(dp[j], dp[j - c] + 1);
            }
        }

        if (dp[target] <= 0) {
            return "0"s;
        }

        string ans;
        ans.reserve(dp[target]);
        for (int i = 8; i >= 0; --i) {
            int c = cost[i];
            while (target - c >= 0 && dp[target] == dp[target - c] + 1) {
                ans.push_back('0' + 1 + i);
                target -= c;
            }
        }

        return ans;
    }
};

TEST(&Solution::largestNumber)