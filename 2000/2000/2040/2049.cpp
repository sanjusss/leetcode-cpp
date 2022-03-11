/*
 * @Author: sanjusss
 * @Date: 2022-03-11 11:05:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-11 11:22:39
 * @FilePath: \2000\2000\2040\2049.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> children(n);
        vector<int> outputs(n);
        for (int i = 1; i < n; ++i) {
            children[parents[i]].push_back(i);
            ++outputs[parents[i]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (outputs[i] == 0) {
                q.push(i);
            }
        }

        vector<int> cnt(n);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int p = parents[i];
            if (p < 0) {
                continue;
            }

            cnt[p] += cnt[i] + 1;
            if (--outputs[p] == 0) {
                q.push(p);
            }
        }

        int64_t score = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int64_t val = 1;
            for (int j : children[i]) {
                val *= cnt[j] + 1;
            }

            if (parents[i] >= 0) {
                val *= n - 1 - cnt[i];
            }

            if (val > score) {
                ans = 1;
                score = val;
            }
            else if (val == score) {
                ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::countHighestScoreNodes)