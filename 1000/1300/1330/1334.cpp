/*
 * @Author: sanjusss
 * @Date: 2023-11-14 09:00:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-14 10:22:38
 * @FilePath: \1000\1300\1330\1334.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<unordered_map<int, int>> dis(n);
        for (auto& e : edges) {
            dis[e[0]][e[1]] = e[2];
            dis[e[1]][e[0]] = e[2];
        }

        vector<unordered_map<int, int>> pass(n);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        for (int i = 0; i < n; ++i) {
            q.emplace(0, i, i);
            pass[i][i] = 0;
        }

        while (!q.empty()) {
            auto [d, i, j] = q.top();
            q.pop();
            for (auto [k, dk] : dis[j]) {
                if (d + dk > distanceThreshold) {
                    continue;
                }

                if (pass[i].count(k) && pass[i][k] <= d + dk) {
                    continue;
                }

                pass[i][k] = d + dk;
                q.emplace(d + dk, i, k);
            }
        }

        int ans = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (pass[i].size() < pass[ans].size()) {
                ans = i;
            }
        }

        return ans;
    }
};