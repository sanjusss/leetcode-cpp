#include "leetcode.h"

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> nexts(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                nexts[manager[i]].push_back(i);
            }
        }

        int ans = 0;
        queue<pair<int, int>> q;
        q.emplace(0, headID);
        while (!q.empty()) {
            auto [t, i] = q.front();
            q.pop();
            ans = max(t, ans);
            t += informTime[i];
            for (int j : nexts[i]) {
                q.emplace(t, j);
            }
        }

        return ans;
    }
};