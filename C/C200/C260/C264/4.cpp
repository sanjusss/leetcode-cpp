/*
 * @Author: sanjusss
 * @Date: 2021-10-24 11:07:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-24 11:15:46
 * @FilePath: \C\C200\C260\C264\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> nexts(n);
        vector<int> needs(n);
        for (auto & r : relations) {
            nexts[r[0] - 1].push_back(r[1] - 1);
            ++needs[r[1] - 1];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < n; ++i) {
            if (needs[i] == 0) {
                q.emplace(time[i], i);
            }
        }

        int ans = 0;
        while (!q.empty()) {
            auto [cur, i] = q.top();
            q.pop();
            ans = cur;
            for (int j : nexts[i]) {
                if (--needs[j] == 0) {
                    q.emplace(cur + time[j], j);
                }
            }
        }

        return ans;
    }
};