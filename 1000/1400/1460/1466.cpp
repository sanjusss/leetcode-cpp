/*
 * @Author: sanjusss
 * @Date: 2023-12-07 08:06:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-07 08:10:17
 * @FilePath: \1000\1400\1460\1466.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> dirs(n);
        for (auto& c : connections) {
            dirs[c[0]].emplace_back(c[1], 1);
            dirs[c[1]].emplace_back(c[0], 0);
        }

        vector<bool> visit(n);
        visit[0] = true;
        queue<int> q;
        q.push(0);
        int ans = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto [j, change] : dirs[i]) {
                if (visit[j]) {
                    continue;
                }

                visit[j] = true;
                ans += change;
                q.push(j);
            }
        }

        return ans;
    }
};