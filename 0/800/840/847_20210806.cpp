/*
 * @Author: sanjusss
 * @Date: 2021-08-06 08:42:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-06 09:54:05
 * @FilePath: \0\800\870\874.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int shortestPathLength(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<vector<int>> states(n, vector<int>(1 << n, INT_MAX));
//         auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
//             auto& [as, ac, al] = a;
//             auto& [bs, bc, bl] = b;
//             if (al != bl) {
//                 return al > bl;
//             }
            
//             int ap = __builtin_popcount(as);
//             int bp = __builtin_popcount(bs);
//             if (ap != bp) {
//                 return ap < bp;
//             }
//             else {
//                 return ac > bc;
//             }
//         };
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> q(cmp);
//         int end = (1 << n) - 1;
//         for (int i = 0; i < n; ++i) {
//             q.emplace(1 << i, i, 0);
//         }

//         while (!q.empty()) {
//             auto [state, cur, len] = q.top();
//             q.pop();
//             if (state == end) {
//                 return len;
//             }

//             for (int next : graph[cur]) {
//                 int nextState = state | (1 << next);
//                 int nextLen = len + 1;
//                 if (states[next][nextState] > nextLen) {
//                     states[next][nextState] = nextLen;
//                     q.emplace(nextState, next, nextLen);
//                 }
//             }
//         }

//         return -1;
//     }
// };

// class Solution {
// public:
//     int shortestPathLength(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<vector<bool>> passed(n, vector<bool>(1 << n));
//         queue<tuple<int, int, int>> q;
//         for (int i = 0; i < n; ++i) {
//             q.emplace(1 << i, i, 0);
//         }

//         int end = (1 << n) - 1;
//         while (!q.empty()) {
//             auto [state, cur, len] = q.front();
//             q.pop();
//             if (state == end) {
//                 return len;
//             }

//             for (int next : graph[cur]) {
//                 int nextState = state | (1 << next);
//                 int nextLen = len + 1;
//                 if (!passed[next][nextState]) {
//                     passed[next][nextState] = true;
//                     q.emplace(nextState, next, nextLen);
//                 }
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                dist[i][j] = 1;
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int all = (1 << n) - 1;
        vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX / 2));
        for (int mask = 1; mask <= all; ++mask) {
            if (mask & (mask - 1)) {
                for (int mi = mask; mi; mi = mi & (mi - 1)) {
                    int i = __builtin_ctz(mi);
                    for (int mj = mask; mj; mj = mj & (mj - 1)) {
                        int j = __builtin_ctz(mj);
                        if (i != j) {
                            dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + dist[j][i]);
                        }
                    }
                }
            }
            else {
                dp[__builtin_ctz(mask)][mask] = 0;
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, dp[i][all]);
        }

        return ans;
    }
};

TEST(&Solution::shortestPathLength)