/*
 * @Author: sanjusss
 * @Date: 2022-07-31 10:24:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-04 14:53:00
 * @FilePath: \C\C300\C300\C304\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> ins(n);
        vector<int> inc(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (edges[i] < 0) {
                q.push(i);
            }
            else {
                ins[edges[i]].push_back(i);
                ++inc[edges[i]];
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

        for (int i = 0; i < n; ++i) {
            if (edges[i] < 0 || inc[i] > 0) {
                continue;
            }

            int j = i;
            do {
                int next = edges[j];
                edges[j] = -1;
                j = next;
            } while (j != -1 && --inc[j] == 0);
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