/*
 * @Author: sanjusss
 * @Date: 2022-07-02 10:00:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-02 11:03:07
 * @FilePath: \0\800\870\871.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         int n = stations.size();
//         vector<int64_t> dp(n + 1);
//         dp[0] = startFuel;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j > 0; --j) {
//                 dp[j] = max(dp[j], dp[j - 1] >= stations[i][0] ? dp[j - 1] + stations[i][1] : 0);
//             }
//         }

//         for (int i = 0; i <= n; ++i) {
//             if (dp[i] >= target) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        int64_t dis = startFuel;
        int n = stations.size();
        priority_queue<int> q;
        for (int i = 0; i <= n; ++i) {
            int64_t arr = i < n ? stations[i][0] : target;
            while (dis < arr && !q.empty()) {
                dis += q.top();
                q.pop();
                ++ans;
            }

            if (dis < arr) {
                return -1;
            }

            if (i < n) {
                q.push(stations[i][1]);
            }
        }

        return ans;
    }
};