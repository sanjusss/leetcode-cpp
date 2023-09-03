/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-03 16:30:59
 * @FilePath: \C\C300\C360\C361\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        static constexpr int sc_maxBits = 13;
        static constexpr int sc_maxWs = 26;
        vector<unordered_map<int, int>> conns(n);
        for (auto& e : edges) {
            conns[e[0]][e[1]] = e[2];
            conns[e[1]][e[0]] = e[2];
        }

        int root = 0;
        for (int i = 1; i < n; ++i) {
            if (conns[i].size() > conns[root].size()) {
                root = i;
            }
        }

        vector<vector<int>> parents(n, vector<int>(sc_maxBits + 1, -1));
        vector<int> heights(n);
        vector<vector<int>> cnts(n);
        cnts[root].resize(sc_maxWs + 1);
        queue<int> q;
        q.push(root);
        for (int h = 0; !q.empty(); ++h) {
            for (int qi = q.size(); qi > 0; --qi) {
                int i = q.front();
                q.pop();
                heights[i] = h;
                for (auto& [j, w] : conns[i]) {
                    if (j == root || parents[j][0] >= 0) {
                        continue;
                    }

                    cnts[j] = cnts[i];
                    cnts[j][w] += 1;

                    parents[j][0] = i;
                    q.push(j);
                }
            }
        }

        for (int b = 1; b <= sc_maxBits; ++b) {
            for (int i = 0; i < n; ++i) {
                if (parents[i][b - 1] >= 0) {
                    parents[i][b] = parents[parents[i][b - 1]][b - 1];
                }
            }
        }

        auto findKth = [&parents] (int node, int k) -> int {
            for (int b = sc_maxBits; b >= 0 && node >= 0; --b) {
                if (k & (1 << b)) {
                    node = parents[node][b];
                }
            }

            return node;
        }; 

        vector<int> ans;
        for (auto& query : queries) {
            int a = query[0];
            int b = query[1];
            int left = 0;
            int right = min(heights[a], heights[b]);
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (findKth(a, heights[a] - mid) == findKth(b, heights[b] - mid)) {
                    left = mid;
                }
                else {
                    right = mid - 1;
                }
            }

            int c = findKth(a, heights[a] - left);
            int sum = 0;
            int use = 0;
            for (int i = 1; i <= sc_maxWs; ++i) {
                int cur = cnts[a][i] + cnts[b][i] - 2 * cnts[c][i];
                sum += cur;
                use = max(use, cur);
            }

            ans.push_back(sum - use);
        }

        return ans;
    }
};

TEST(&Solution::minOperationsQueries)