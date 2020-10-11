/*
 * @Author: sanjusss
 * @Date: 2020-10-11 11:23:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-11 15:01:39
 * @FilePath: \C\C200\C200\C210\4.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> dis(n + 1, vector<int>(n + 1));
//         vector<unordered_set<int>> conns(n + 1);
//         vector<queue<int>> qs(n + 1);
//         for (auto& edge : edges) {
//             conns[edge[0]].insert(edge[1]);
//             conns[edge[1]].insert(edge[0]);
//             dis[edge[0]][edge[1]] = 1;
//             dis[edge[1]][edge[0]] = 1;
//             qs[edge[0]].push(edge[1]);
//             qs[edge[1]].push(edge[0]);
//         }

//         int d = 1;
//         while (true) {
//             bool end = true;
//             ++d;
//             for (int i = 1; i <= n; ++i) {
//                 auto& q = qs[i];
//                 if (!q.empty()) {
//                     end = false;
//                 }

//                 for (int j = q.size(); j > 0; --j) {
//                     int v = q.front();
//                     q.pop();
//                     for (int k : conns[v]) {
//                         if (k == i || dis[i][k] > 0) {
//                             continue;
//                         }

//                         dis[i][k] = d;
//                         q.push(k);
//                     }
//                 }
//             }

//             if (end) {
//                 break;
//             }
//         }
        
//         vector<int> ans(n - 1);
//         for (int i = 1; i <= n; ++i) {
//             for (int j = i + 1; j <= n; ++j) {
//                 ++ans[dis[i][j] - 1];
//             }
//         }

//         for (int i = 1; i < n - 1; ++i) {
//             if (ans[i] == 0) {
//                 continue;
//             }

//             ans[i] = 1 << (ans[i] - 1);
//         }

//         return ans;
//     }
// };