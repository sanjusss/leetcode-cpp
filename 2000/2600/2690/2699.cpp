/*
 * @Author: sanjusss
 * @Date: 2023-06-09 09:07:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-09 11:43:37
 * @FilePath: \2000\2600\2690\2699.cpp
 */
#include "leetcode.h"

// 时间复杂度 O(n * log(target) * mlogm)
// class Solution {
// public:
//     vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int
//     target) {
//         static constexpr int sc_maxEdge = 1e9;
//         vector<unordered_map<int, int>> conns(n);
//         vector<int> mods;
//         for (int i = 0; i < edges.size(); ++i) {
//             auto& e = edges[i];
//             if (e[2] < 0) {
//                 mods.push_back(i);
//             }
//             else {
//                 conns[e[0]][e[1]] = e[2];
//                 conns[e[1]][e[0]] = e[2];
//             }
//         }

//         // 1 表示最短距离大于target
//         // 0 表示最短距离等于target
//         // -1 表示最短距离小于target
//         auto check = [&]() -> int {
//             vector<int> dis(n, INT_MAX);
//             dis[source] = 0;
//             priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
//             q.emplace(0, source);
//             while (!q.empty()) {
//                 auto [cur, i] = q.top();
//                 q.pop();
//                 if (dis[i] < cur) {
//                     continue;
//                 }
//                 else if (i == destination) {
//                     if (cur < target) {
//                         return -1;
//                     }
//                     else if (cur > target) {
//                         return 1;
//                     }
//                     else {
//                         return 0;
//                     }
//                 }

//                 for (auto [j, d] : conns[i]) {
//                     if (dis[j] <= cur + d) {
//                         continue;
//                     }

//                     dis[j] = cur + d;
//                     if (dis[j] > target) {
//                         continue;
//                     }

//                     q.emplace(dis[j], j);
//                 }
//             }

//             return 1;
//         };

//         if (check() < 0) {
//             return {};
//         }

//         for (int i : mods) {
//             auto& e = edges[i];
//             conns[e[0]][e[1]] = 1;
//             conns[e[1]][e[0]] = 1;
//             e[2] = 1;
//         }

//         switch (check()) {
//             case 1:
//                 return {};

//             case 0:
//                 return edges;

//             default:
//                 break;
//         }

//         for (int i : mods) {
//             auto& e = edges[i];
//             conns[e[0]][e[1]] = target;
//             conns[e[1]][e[0]] = target;
//             e[2] = target;
//         }

//         for (int i : mods) {
//             auto& e = edges[i];
//             auto& m1 = conns[e[0]][e[1]];
//             auto& m2 = conns[e[1]][e[0]];
//             auto& m3 = e[2];
//             int left = 0;
//             int right = target + 1;
//             while (left <= right) {
//                 int mid = (left + right) / 2;
//                 m1 = mid;
//                 m2 = mid;
//                 m3 = mid;
//                 int res = check();
//                 if (res == 0) {
//                     if (mid >= 1 && mid <= target) {
//                         return edges;
//                     }
//                     else {
//                         break;
//                     }
//                 }
//                 else if (res > 0) {
//                     right = mid - 1;
//                 }
//                 else {
//                     left = mid + 1;
//                 }
//             }

//             m1 = 1;
//             m2 = 1;
//             m3 = 1;
//         }

//         return {};
//     }
// };

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        static constexpr int sc_maxEdge = 1e9;
        vector<unordered_map<int, int>> conns(n);
        vector<int> mods;
        for (int i = 0; i < edges.size(); ++i) {
            auto& e = edges[i];
            if (e[2] < 0) {
                mods.push_back(i);
            }
            else {
                conns[e[0]][e[1]] = e[2];
                conns[e[1]][e[0]] = e[2];
            }
        }

        auto check = [&]() -> int {
            vector<int> dis(n, INT_MAX);
            dis[source] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
            q.emplace(0, source);
            while (!q.empty()) {
                auto [cur, i] = q.top();
                q.pop();
                if (dis[i] < cur) {
                    continue;
                }
                else if (i == destination) {
                    return cur;
                }

                for (auto [j, d] : conns[i]) {
                    if (dis[j] <= cur + d) {
                        continue;
                    }

                    dis[j] = cur + d;
                    q.emplace(dis[j], j);
                }
            }

            return INT_MAX;
        };

        if (check() < target) {
            return {};
        }

        for (int i : mods) {
            auto& e = edges[i];
            conns[e[0]][e[1]] = target;
            conns[e[1]][e[0]] = target;
            e[2] = target;
        }

        if (check() == target) {
            return edges;
        }

        for (int i : mods) {
            auto& e = edges[i];
            auto& m1 = conns[e[0]][e[1]];
            auto& m2 = conns[e[1]][e[0]];
            auto& m3 = e[2];
            m1 = 1;
            m2 = 1;
            m3 = 1;
            int next = check();
            if (next <= target) {
                m3 = (target - next) + 1;
                return edges;
            }
        }

        return {};
    }
};

TEST(&Solution::modifiedGraphEdges)