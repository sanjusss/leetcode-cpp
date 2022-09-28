/*
 * @Author: sanjusss
 * @Date: 2022-09-28 16:28:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-28 17:00:21
 * @FilePath: \chengxuyuanmianshijindian\1709.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int getKthMagicNumber(int k) {
//         int ans = 0;
//         priority_queue<int, vector<int>, greater<>> q;
//         q.push(1);
//         while (--k >= 0 && !q.empty()) {
//             ans = q.top();
//             do {
//                 q.pop();
//             } while (!q.empty() && q.top() == ans);
//             if (ans <= INT_MAX / 3) {
//                 q.push(ans * 3);
//             }
//             if (ans <= INT_MAX / 5) {
//                 q.push(ans * 5);
//             }
//             if (ans <= INT_MAX / 7) {
//                 q.push(ans * 7);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int64_t> dp(k + 1);
        dp[1] = 1;
        int a = 1;
        int b = 1;
        int c = 1;
        for (int i = 2; i <= k; ++i) {
            dp[i] = min({ dp[a] * 3, dp[b] * 5, dp[c] * 7 });
            if (dp[i] == dp[a] * 3) {
                ++a;
            }
            if (dp[i] == dp[b] * 5) {
                ++b;
            }
            if (dp[i] == dp[c] * 7) {
                ++c;
            }
        }

        return dp[k];
    }
};

TEST(&Solution::getKthMagicNumber)