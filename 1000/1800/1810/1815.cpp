/*
 * @Author: sanjusss
 * @Date: 2023-01-22 09:59:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-22 12:45:12
 * @FilePath: \1000\1800\1810\1815.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxHappyGroups(int batchSize, vector<int>& groups) {
//         int n = groups.size();
//         vector<int> dp(1 << n);
//         int end = (1 << n) - 1;
//         for (int mask = 0; mask < end; ++mask) {
//             int sum = 0;
//             for (int i = 0; i < n; ++i) {
//                 if (mask & (1 << i)) {
//                     sum += groups[i];
//                     sum %= batchSize;
//                 }
//             }

//             int add = sum == 0 ? 1 : 0;
//             for (int i = 0; i < n; ++i) {
//                 if (!(mask & (1 << i))) {
//                     dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + add);
//                 }
//             }
//         }

//         return dp.back();
//     }
// };

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> cnt(batchSize);
        for (int i : groups) {
            ++cnt[i % batchSize];
        }

        static constexpr int64_t mask5 = 0x1F;
        auto toMask = [batchSize](const vector<int>& cur) {
            int64_t mask = 0;
            for (int i = 0; i < batchSize; ++i) {
                mask <<= 5;
                mask += cur[i];
            }

            return mask;
        };
        auto fromMask = [batchSize](int64_t mask, vector<int>& cur) {
            for (int i = batchSize - 1; i >= 0; --i) {
                cur[i] = mask & mask5;
                mask >>= 5;
            }
        };

        int64_t target = toMask(cnt);

        unordered_map<int64_t, int> dp;
        dp[0] = 0;
        queue<int64_t> q;
        q.push(0);
        vector<int> states(batchSize);
        while (!q.empty()) {
            int64_t cur = q.front();
            q.pop();
            fromMask(cur, states);
            int sum = 0;
            for (int i = 0; i < batchSize; ++i) {
                sum += i * states[i];
                sum %= batchSize;
            }
            
            int add = sum == 0 ? 1 : 0;
            for (int i = 0; i < batchSize; ++i) {
                if (++states[i] <= cnt[i]) {
                    int64_t next = toMask(states);
                    if (!dp.count(next)) {
                        q.push(next);
                    }

                    dp[next] = max(dp[next], dp[cur] + add);
                }

                --states[i];
            }
        }

        return dp[target];
    }
};

TEST(&Solution::maxHappyGroups)