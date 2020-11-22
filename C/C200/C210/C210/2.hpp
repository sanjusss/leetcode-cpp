/*
 * @Author: sanjusss
 * @Date: 2020-10-11 10:34:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-11 10:42:47
 * @FilePath: \C\C200\C200\C210\2.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> conns(n, vector<bool>(n));
        vector<int> rs(n);
        for (auto& i : roads) {
            conns[i[0]][i[1]] = true;
            conns[i[1]][i[0]] = true;
            ++rs[i[0]];
            ++rs[i[1]];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int v = rs[i] + rs[j];
                if (conns[i][j]) {
                    --v;
                }

                ans = max(ans, v);
            }
        }

        return ans;
    }
};