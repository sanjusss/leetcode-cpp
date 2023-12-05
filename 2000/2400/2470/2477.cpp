#include "leetcode.h"

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> conns(n);
        for (auto& r : roads) {
            conns[r[0]].push_back(r[1]);
            conns[r[1]].push_back(r[0]);
        }

        vector<bool> vis(n);
        vector<int> wait(n);
        vector<int> next(n);
        vis[0] = true;
        stack<int> s;
        s.push(0);
        next[0] = -1;
        while (!s.empty()) {
            int i = s.top();
            s.pop();
            for (int j : conns[i]) {
                if (vis[j]) {
                    continue;
                }

                ++wait[i];
                next[j] = i;
                vis[j] = true;
                s.push(j);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (wait[i] == 0) {
                s.push(i);
            }
        }

        long long ans = 0;
        vector<int> cnt(n, 1);
        while (!s.empty()) {
            int i = s.top();
            s.pop();
            int j = next[i];
            if (j < 0) {
                continue;
            }

            ans += (cnt[i] + seats - 1) / seats;
            cnt[j] += cnt[i];
            if (--wait[j] > 0) {
                continue;
            }

            s.push(j);
        }

        return ans;
    }
};