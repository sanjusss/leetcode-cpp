/*
 * @Author: sanjusss
 * @Date: 2023-12-08 08:43:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-08 09:13:26
 * @FilePath: \2000\2000\2000\2008.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
//         sort(rides.begin(), rides.end());
//         long long ans = 0;
//         long long pre = 0;
//         priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<>> q;
//         for (auto& r : rides) {
//             int start = r[0];
//             int stop = r[1];
//             long long earn = stop - start + r[2];
//             while (!q.empty() && q.top().first <= start) {
//                 pre = max(pre, q.top().second);
//                 q.pop();
//             }

//             earn += pre;
//             ans = max(ans, earn);
//             q.emplace(stop, earn);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, int>>> diffs(n + 1);
        for (auto& r : rides) {
            diffs[r[1]].emplace_back(r[0], r[1] - r[0] + r[2]);
        }

        vector<long long> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (auto& [start, earn] : diffs[i]) {
                dp[i] = max(dp[i], dp[start] + earn);
            }
        }

        return dp[n];
    }
};