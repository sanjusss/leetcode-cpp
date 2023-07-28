#include "leetcode.h"

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> pres(n);
        vector<vector<int>> nxts(n);
        for (auto& r : relations) {
            ++pres[r[1] - 1];
            nxts[r[0] - 1].push_back(r[1] - 1);
        }

        vector<int> started(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (pres[i] == 0) {
                q.emplace(i);
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int cur = started[i] + time[i];
            ans = max(ans, cur);
            for (int j : nxts[i]) {
                started[j] = max(started[j], cur);
                if (--pres[j] == 0) {
                    q.emplace(j);
                }
            }
        }

        return ans;
    }
};