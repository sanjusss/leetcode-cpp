#pragma once
#include "leetcode.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> used(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }

            ++ans;
            queue<int> q;
            q.push(i);
            used[i] = true;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < n; ++j) {
                    if (cur == j || used[j] || isConnected[cur][j] == 0) {
                        continue;
                    }

                    used[j] = true;
                    q.push(j);
                }
            }
        }

        return ans;
    }
};