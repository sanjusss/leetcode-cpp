/*
 * @Author: sanjusss
 * @Date: 2024-01-26 09:53:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-01-26 11:08:14
 * @FilePath: \2000\2800\2840\2846.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        static const int sc_MaxPow = 13; // 一步最大向上查找2 << sc_MaxPow层
        vector<unordered_map<int, int>> conns(n);
        for (auto &e : edges) {
            conns[e[0]][e[1]] = e[2];
            conns[e[1]][e[0]] = e[2];
        }

        int root = 0;
        for (int i = 1; i < n; ++i) {
            if (conns[i].size() > conns[root].size()) {
                root = i;
            }
        }

        vector<vector<int>> cnts(n, vector<int>(26 + 1)); // 从点i到root，有多少条w边
        vector<vector<int>> parents(n, vector<int>(sc_MaxPow + 1, -1)); // 点i的2^j级父节点
        vector<int> heights(n); // 到根节点的距离
        queue<int> q;
        q.push(root);
        for (int h = 0; !q.empty(); ++h) {
            for (int qi = q.size(); qi > 0; --qi) {
                int i = q.front();
                q.pop();
                heights[i] = h;

                for (auto [j, w] : conns[i]) {
                    if (j == root || parents[j][0] >= 0) {
                        continue;
                    }

                    parents[j][0] = i;
                    for (int k = 1; k <= sc_MaxPow && parents[j][k - 1] >= 0; ++k) {
                        parents[j][k] = parents[parents[j][k - 1]][k - 1];
                    }

                    for (int k = 1; k <= 26; ++k) {
                        cnts[j][k] = cnts[i][k] + (w == k ? 0 : 1);
                    }

                    q.push(j);
                }
            }
        }

        auto lca = [&] (int a, int b) -> int {
            if (heights[a] < heights[b]) {
                swap(a, b);
            }

            for (int h = heights[a] - heights[b], mv = 0; h; h >>= 1, ++mv) {
                if (h & 1) {
                    a = parents[a][mv];
                }
            }

            for (int mv = sc_MaxPow; mv >= 0 && a != b; --mv) {
                if (parents[a][mv] != parents[b][mv]) {
                    a = parents[a][mv];
                    b = parents[b][mv];
                }
            }

            if (a == b) {
                return a;
            }
            else {
                return parents[a][0];
            }
        };

        vector<int> ans;
        for (auto &q : queries) {
            int a = q[0];
            int b = q[1];
            int p = lca(a, b);
            int res = n;
            for (int w = 1; w <= 26; ++w) {
                res = min(res, cnts[a][w] + cnts[b][w] - 2 * cnts[p][w]);
            }

            ans.push_back(res);
        }

        return ans;
    }
};

TEST(&Solution::minOperationsQueries)