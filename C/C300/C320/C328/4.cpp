/*
 * @Author: sanjusss
 * @Date: 2023-01-15 10:23:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-15 11:12:26
 * @FilePath: \C\C300\C320\C328\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> conns(n);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            conns[e[1]].push_back(e[0]);
        }

        vector<unordered_map<int, int64_t>> outs(n);
        vector<bool> used(n);
        function<int64_t(int)> dfs = [&] (int i) -> int64_t {
            int64_t d = 0;
            used[i] = true;
            for (int j : conns[i]) {
                if (used[j]) {
                    continue;
                }

                if (!outs[i].count(j)) {
                    outs[i][j] = dfs(j);
                }

                d = max(d, outs[i][j]);
            }

            used[i] = false;
            return d + price[i];
        };

        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            if (conns[i].size() != 1) {
                continue;
            }

            ans = max(ans, dfs(i) - price[i]);
        }

        return ans;
    }
};