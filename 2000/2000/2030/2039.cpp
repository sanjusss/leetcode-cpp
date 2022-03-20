/*
 * @Author: sanjusss
 * @Date: 2022-03-20 09:56:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-20 10:15:25
 * @FilePath: \2000\2000\2030\2039.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> conns(n);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            conns[e[1]].push_back(e[0]);
        }

        int ans = 0;
        vector<bool> passed(n);
        passed[0] = true;
        queue<int> q;
        q.push(0);
        for (int s = 0; !q.empty(); ++s) {
            for (int i = q.size(); i > 0; --i) {
                int j = q.front();
                q.pop();

                for (int k : conns[j]) {
                    if (!passed[k]) {
                        q.push(k);
                        passed[k] = true;
                    }
                }

                if (j == 0) {
                    continue;
                }

                int stopSend = s * 2;
                int finalSend = (stopSend - 1) - (stopSend - 1) % patience[j];
                ans = max(ans, stopSend + finalSend + 1);
            }
        }

        return ans;
    }
};