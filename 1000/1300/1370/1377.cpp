/*
 * @Author: sanjusss
 * @Date: 2023-05-24 09:38:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-24 09:46:28
 * @FilePath: \1000\1300\1370\1377.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> conns(n + 1);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            conns[e[1]].push_back(e[0]);
        }

        queue<pair<int, double>> q;
        q.emplace(1, 1.0);
        vector<bool> pass(n + 1);
        pass[1] = true;
        for (int ti = 0; ti < t && !q.empty(); ++ti) {
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, p] = q.front();
                q.pop();
                int next = i == 1 ? conns[i].size() : conns[i].size() - 1;
                if (next == 0) {
                    if (i == target) {
                        return p;
                    }
                    else {
                        continue;
                    }
                }

                p /= next;
                for (int j : conns[i]) {
                    if (pass[j]) {
                        continue;
                    }

                    pass[j] = true;
                    q.emplace(j, p);
                }
            }
        }

        while (!q.empty()) {
            auto [i, p] = q.front();
            q.pop();
            if (i == target) {
                return p;
            }
        }

        return 0.0;
    }
};