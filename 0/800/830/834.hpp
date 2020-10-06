/*
 * @Author: sanjusss
 * @Date: 2020-10-06 07:21:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-06 08:24:11
 * @FilePath: \0\800\830\834.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<unordered_set<int>> conns(N);
        for (auto& i : edges) {
            conns[i[0]].insert(i[1]);
            conns[i[1]].insert(i[0]);
        }

        vector<int> ans(N);
        vector<bool> passed(N);
        for (int i = 0; i < N; ++i) {
            fill(passed.begin(), passed.end(), false);
            passed[i] = true;
            int d = 0;
            queue<int> q;
            q.push(i);
            int sum = 0;
            do {
                ++d;
                for (int j = q.size(); j > 0; --j) {
                    int cur = q.front();
                    q.pop();
                    for (int k : conns[cur]) {
                        if (passed[k]) {
                            continue;
                        }

                        passed[k] = true;
                        sum += d;
                        q.push(k);
                    }
                }
            } while (!q.empty());
            ans[i] = sum;
        }

        return ans;
    }
};