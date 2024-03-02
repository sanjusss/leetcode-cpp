#include "leetcode.h"

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> conns(n);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            conns[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n);
        for (int i : restricted) {
            vis[i] = true;
        }

        vis[0] = true;
        int ans = 0;
        stack<int> s;
        s.push(0);
        while (!s.empty()) {
            ++ans;
            int i = s.top();
            s.pop();
            for (int j : conns[i]) {
                if (vis[j]) {
                    continue;
                }

                vis[j] = true;
                s.push(j);
            }
        }

        return ans;
    }
};