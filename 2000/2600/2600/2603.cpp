#include "leetcode.h"

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> conns(n);
        vector<int> degrees(n);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            ++degrees[e[0]];
            conns[e[1]].push_back(e[0]);
            ++degrees[e[1]];
        }

        vector<int> rs(n, INT_MAX);
        queue<int> q;
        vector<bool> pass(n);
        for (int i = 0; i < n; ++i) {
            if (coins[i] != 0) {
                rs[i] = 2;
            }

            if (degrees[i] == 1) {
                pass[i] = true;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : conns[i]) {
                if (pass[j]) {
                    continue;
                }

                rs[j] = min(rs[j], rs[i] - 1);
                if (rs[j] == 0) {
                    continue;
                }

                if (--degrees[j] > 1) {
                    continue;
                }

                pass[j] = true;
                q.push(j);
            }
        }

        int ans = 0;
        for (auto& e : edges) {
            if (pass[e[0]] == false && pass[e[1]] == false) {
                ++ans;
            }
        }

        return ans * 2;
    }
};