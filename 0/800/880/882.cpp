/*
 * @Author: sanjusss
 * @Date: 2022-11-26 09:17:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-26 09:38:54
 * @FilePath: \0\800\880\882.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<unordered_map<int, int>> conns(n);
        for (auto& e : edges) {
            conns[e[0]][e[1]] = e[2];
            conns[e[1]][e[0]] = e[2];
        }

        vector<int> remains(n, -1);
        priority_queue<pair<int, int>> q;
        q.emplace(maxMoves, 0);
        while (!q.empty()) {
            auto [moves, i] = q.top();
            q.pop();
            if (remains[i] >= moves) {
                continue;
            }

            remains[i] = moves;
            for (auto [j, pts] : conns[i]) {
                if (remains[j] >= moves - pts - 1) {
                    continue;
                }

                q.emplace(moves - pts - 1, j);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (remains[i] >= 0) {
                ++ans;
            }

            for (auto [j, pts] : conns[i]) {
                if (j < i) {
                    continue;
                }

                int p = max(remains[i], 0) + max(remains[j], 0);
                ans += min(pts, p);
            }
        }

        return ans;
    }
};