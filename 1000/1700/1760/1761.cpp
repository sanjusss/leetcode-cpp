/*
 * @Author: sanjusss
 * @Date: 2023-08-31 08:20:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-31 08:58:32
 * @FilePath: \1000\1700\1760\1761.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minTrioDegree(int n, vector<vector<int>>& edges) {
//         vector<set<int>> conns(n + 1);
//         for (auto& e : edges) {
//             conns[e[0]].insert(e[1]);
//             conns[e[1]].insert(e[0]);
//         }

//         int ans = INT_MAX;
//         for (int i = 1; i <= n; ++i) {
//             auto end = conns[i].lower_bound(i);
//             for (auto tj = conns[i].begin(); tj != end; ++tj) {
//                 for (auto tk = next(tj); tk != end; ++tk) {
//                     if (conns[*tj].count(*tk)) {
//                         int cnt = conns[i].size() + conns[*tj].size() + conns[*tk].size() - 6;
//                         ans = min(ans, cnt);
//                     }
//                 }
//             }
//         }

//         if (ans == INT_MAX) {
//             return -1;
//         }
//         else {
//             return ans;
//         }
//     }
// };

// class Solution {
// public:
//     int minTrioDegree(int n, vector<vector<int>>& edges) {
//         vector<unordered_set<int>> conns(n + 1);
//         vector<int> degrees(n + 1);
//         for (auto& e : edges) {
//             ++degrees[e[0]];
//             conns[e[0]].insert(e[1]);
//             ++degrees[e[1]];
//             conns[e[1]].insert(e[0]);
//         }

//         vector<unordered_set<int>> dirconns(n + 1);
//         for (int i = 1; i <= n; ++i) {
//             for (int j : conns[i]) {
//                 if (degrees[i] < degrees[j] || (degrees[i] == degrees[j] && i < j)) {
//                     dirconns[i].insert(j);
//                 }
//             }
//         }

//         int ans = INT_MAX;
//         for (int i = 1; i <= n; ++i) {
//             for (int j : dirconns[i]) {
//                 for (int k : dirconns[j]) {
//                     if (!dirconns[i].count(k)) {
//                         continue;
//                     }

//                     ans = min(ans, degrees[i] + degrees[j] + degrees[k] - 6);
//                 }
//             }
//         }

//         if (ans == INT_MAX) {
//             return -1;
//         }
//         else {
//             return ans;
//         }
//     }
// };

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> conns(n + 1, vector<bool>(n + 1));
        vector<int> degrees(n + 1);
        for (auto& e : edges) {
            ++degrees[e[0]];
            conns[e[0]][e[1]] = true;
            ++degrees[e[1]];
            conns[e[1]][e[0]] = true;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!conns[i][j]) {
                    continue;
                }

                for (int k = j + 1; k <= n; ++k) {
                    if (conns[i][k] && conns[j][k]) {
                        ans = min(ans, degrees[i] + degrees[j] + degrees[k] - 6);
                    }
                }
            }
        }

        if (ans == INT_MAX) {
            return -1;
        }
        else {
            return ans;
        }
    }
};