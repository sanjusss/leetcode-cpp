/*
 * @Author: sanjusss
 * @Date: 2021-08-24 08:24:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-24 08:56:42
 * @FilePath: \0\700\780\787.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<unordered_map<int, int>> conn(n);
//         for (auto& f : flights) {
//             conn[f[0]][f[1]] = f[2];
//         }

//         vector<vector<int>> passed(n, vector<int>(k + 1, INT_MAX));
//         fill(passed[src].begin(), passed[src].end(), 0);
//         auto cmp = [] (const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
//             return get<0>(a) > get<0>(b);
//         };
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> q(cmp);
//         q.emplace(0, src, -1);
//         while (!q.empty()) {
//             auto [dis, pt, trans] = q.top();
//             q.pop();
//             if (pt == dst) {
//                 return dis;
//             }
//             else if (trans == k) {
//                 continue;
//             }

//             ++trans;
//             for (auto [next, d] : conn[pt]) {
//                 int nextDis = d + dis;
//                 if (passed[next][trans] <= nextDis) {
//                     continue;
//                 }

//                 passed[next][trans] = nextDis;
//                 q.emplace(nextDis, next, trans);
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        static constexpr int inf = 1e5;
        int ans = inf;
        vector<int> prev(n);
        vector<int> cur(n, inf);
        cur[src] = 0;
        for (int i = 0; i <= k; ++i) {
            swap(cur, prev);
            fill(cur.begin(), cur.end(), inf);
            for (auto& f : flights) {
                cur[f[1]] = min(cur[f[1]], prev[f[0]] + f[2]);
            }

            ans = min(ans, cur[dst]);
        }

        return ans == inf ? -1 : ans;
    }
};

TEST(&Solution::findCheapestPrice)