/*
 * @Author: sanjusss
 * @Date: 2023-10-15 10:48:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-05 11:00:11
 * @FilePath: \C\C300\C370\C370\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<unordered_set<int>> conns(n);
        for (auto& e : edges) {
            conns[e[0]].insert(e[1]);
            conns[e[1]].insert(e[0]);
        }

        vector<bool> visits(n);
        function<pair<long long, long long>(int)> dfs = [&] (int i) -> pair<long long, long long> {
            long long take = 0;
            long long keep = 0;
            bool isLeaf = true;
            for (int j : conns[i]) {
                if (visits[j]) {
                    continue;
                }

                visits[j] = true;
                isLeaf = false;
                auto [valid, invalid] = dfs(j);
                take += valid;
                keep += invalid;
            }

            return { max(take + (isLeaf ? 0 : values[i]), keep), keep + values[i] };
        };

        visits[0] = true;
        return dfs(0).first;
    }
};

TEST(&Solution::maximumScoreAfterOperations)