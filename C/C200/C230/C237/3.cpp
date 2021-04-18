#include "leetcode.h"

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        map<int, vector<int>> enqueueOrders;
        for (int i = 0; i < n; ++i) {
            enqueueOrders[tasks[i][0]].push_back(i);
        }

        auto cmp = [&tasks](int a, int b) {
            if (tasks[a][1] == tasks[b][1]) {
                return a > b;
            }
            else {
                return tasks[a][1] > tasks[b][1];
            }
        };

        vector<int> ans;
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        int run = 0;
        for (auto& [t, vec] : enqueueOrders) {
            if (run < t) {
                while (!q.empty() && run < t) {
                    int i = q.top();
                    q.pop();
                    run = max(run, tasks[i][0]) + tasks[i][1];
                    ans.push_back(i);
                }
            }

            for (int i : vec) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int i = q.top();
            q.pop();
            ans.push_back(i);
        }

        return ans;
    }
};