/*
 * @Author: sanjusss
 * @Date: 2024-03-05 11:05:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-03-05 11:29:05
 * @FilePath: \1000\1900\1970\1976.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        static const int64_t mod = 1e9 + 7;
        vector<unordered_map<int, int>> conns(n);
        for (auto& r : roads) {
            conns[r[0]][r[1]] = r[2];
            conns[r[1]][r[0]] = r[2];
        }

        vector<pair<int64_t, int64_t>> cnts(n, pair<int64_t, int64_t>(INT64_MAX, 0));
        cnts[0] = { 0, 1 };
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> q;
        q.emplace(0, 0);
        while (!q.empty() && q.top().second != n - 1) {
            auto [d, i] = q.top();
            q.pop();
            if (cnts[i].first < d) {
                continue;
            }

            for (auto [j, dx] : conns[i]) {
                int64_t nx = d + dx;
                if (cnts[j].first < nx) {
                    continue;
                }
                else if (cnts[j].first == nx) {
                    cnts[j].second += cnts[i].second;
                    cnts[j].second %= mod;
                }
                else {
                    cnts[j].first = nx;
                    cnts[j].second = cnts[i].second;
                    q.emplace(nx, j);
                }
            }
        }

        return cnts[n - 1].second;
    }
};