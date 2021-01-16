#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int& i : group) {
            if (i == -1) {
                i = m++;
            }
        }

        vector<int> groupIn(m);
        vector<vector<int>> groupConn(m);
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                if (group[i] == group[j]) {
                    continue;
                }

                ++groupIn[group[i]];
                groupConn[group[j]].push_back(group[i]);
            }
        }

        queue<int> groupQ;
        for (int i = 0; i < m; ++i) {
            if (groupIn[i] == 0) {
                groupQ.push(i);
            }
        }

        vector<int> groupOrder;
        while (!groupQ.empty()) {
            int i = groupQ.front();
            groupQ.pop();
            groupOrder.push_back(i);
            for (int j : groupConn[i]) {
                if (--groupIn[j] == 0) {
                    groupQ.push(j);
                }
            }
        }

        if (groupOrder.size() != m) {
            return {};
        }

        vector<vector<int>> groupItems(m);
        for (int i = 0; i < n; ++i) {
            groupItems[group[i]].push_back(i);
        }

        vector<int> ans;
        for (int g : groupOrder) {
            auto& items = groupItems[g];
            unordered_map<int, int> in;
            unordered_map<int, unordered_set<int>> conn;
            queue<int> q;
            for (int i : items) {
                for (int j : beforeItems[i]) {
                    if (group[j] != g) {
                        continue;
                    }

                    ++in[i];
                    conn[j].insert(i);
                }

                if (in[i] == 0) {
                    q.push(i);
                }
            }

            int cnt = 0;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                ans.push_back(i);
                ++cnt;
                for (int j : conn[i]) {
                    if (--in[j] == 0) {
                        q.push(j);
                    }
                }
            }

            if (cnt != items.size()) {
                return {};
            }
        }

        return ans;
    }
};