/*
 * @Author: sanjusss
 * @Date: 2021-11-11 15:30:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-11 17:31:23
 * @FilePath: \0\600\620\629.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int kInversePairs(int n, int k) {
//         static constexpr int mod = 1e9 + 7;
//         vector<int> cur(k + 1);
//         vector<int> prev(k + 1);
//         cur[0] = 1;
//         for (int i = 1; i <= n; ++i) {
//             swap(cur, prev);
//             fill(cur.begin(), cur.end(), 0);
//             int maxMove = i - 1;  // 单次向左移动的最大次数
//             for (int lastMove = 0; lastMove <= k; ++lastMove) {
//                 for (int move = min(maxMove, k - lastMove); move >= 0; --move) {
//                     cur[lastMove + move] += prev[lastMove];
//                     cur[lastMove + move] %= mod;
//                 }
//             }
//         }

//         return cur[k];
//     }
// };

class Solution {
public:
    int kInversePairs(int n, int k) {
        static constexpr int mod = 1e9 + 7;
        vector<int> cur(k + 1);
        vector<int> prev(k + 1);
        cur[0] = 1;
        int lastMaxTotoal = 0;
        for (int i = 1; i <= n; ++i) {
            swap(cur, prev);
            fill(cur.begin(), cur.end(), 0);
            int maxMove = i - 1;  // 单次向左移动的最大次数
            lastMaxTotoal = min(k, lastMaxTotoal + maxMove);
            cur[0] = 1;
            for (int total = 1; total <= lastMaxTotoal; ++total) {
                cur[total] += cur[total - 1];
                cur[total] += prev[total];
                cur[total] %= mod;
                if (total > maxMove) {
                    cur[total] += mod - prev[total - maxMove - 1];
                    cur[total] %= mod;
                }
            }
        }

        return cur[k];
    }
};

TEST(&Solution::kInversePairs)