/*
 * @Author: sanjusss
 * @Date: 2021-12-15 08:56:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-15 09:22:13
 * @FilePath: \0\800\850\851.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> poor(n);
        vector<int> in(n);
        for (auto& r : richer) {
            poor[r[0]].push_back(r[1]);
            ++in[r[1]];
        }

        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : poor[i]) {
                if (quiet[ans[i]] < quiet[ans[j]]) {
                    ans[j] = ans[i];
                }

                if (--in[j] == 0) {
                    q.push(j);
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::loudAndRich)