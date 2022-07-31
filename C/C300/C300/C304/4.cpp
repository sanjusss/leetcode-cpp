/*
 * @Author: sanjusss
 * @Date: 2022-07-31 10:24:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-31 11:32:48
 * @FilePath: \C\C300\C300\C304\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> ins(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (edges[i] < 0) {
                q.push(i);
            }
            else {
                ins[edges[i]].push_back(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            edges[i] = -1;
            for (int j : ins[i]) {
                q.push(j);
            }
        }

        int ans = -1;
        vector<int> passed(n);
        for (int i = 0; i < n; ++i) {
            if (edges[i] < 0 || passed[i] > 0) {
                continue;
            }

            int dis = 1;
            int j = i;
            while (passed[j] == 0) {
                passed[j] = dis++;
                j = edges[j];
            }

            ans = max(ans, dis - passed[j]);
        }

        return ans;
    }
};

TEST(&Solution::longestCycle)