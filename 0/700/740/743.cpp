/*
 * @Author: sanjusss
 * @Date: 2021-08-02 10:08:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-02 10:23:44
 * @FilePath: \0\700\740\743.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<unordered_map<int, int>> conn(n + 1);
        for (auto& t : times) {
            conn[t[0]][t[1]] = t[2];
        }

        int cnt = n;
        vector<bool> passed(n + 1);
        vector<int> fast(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, k);
        fast[k] = 0;
        int ans = 0;
        while (!q.empty() && cnt > 0) {
            auto [t, i] = q.top();
            q.pop();
            if (passed[i]) {
                continue;
            } 
            else {
                passed[i] = true;
                ans = t;
                --cnt;
            }

            for (auto& [ni, nt] : conn[i]) {
                if (!passed[ni] && nt + t < fast[ni]) {
                    q.emplace(nt + t, ni);
                    fast[ni] = nt + t;
                }
            }
        }

        return cnt == 0 ? ans : -1;
    }
};

TEST(&Solution::networkDelayTime)