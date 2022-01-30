/*
 * @Author: sanjusss
 * @Date: 2022-01-24 09:56:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-24 11:13:53
 * @FilePath: \2000\2000\2040\2045.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> conns(n + 1);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            conns[e[1]].push_back(e[0]);
        }

        vector<int> pass(n + 1, - 1);
        vector<int> cnt(n + 1, 0);
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> q;
        q.emplace(0, 1);
        pass[1] = 0;
        cnt[1] = 1;
        int arr = -1;
        while (!q.empty()) {
            auto [t, i] = q.top();
            q.pop();
            if (t > pass[i]) {
                continue;
            }

            if (i == n) {
                if (arr >= 0 && t > arr) {
                    return t;
                }
                else {
                    arr = t;
                }
            }

            if ((t / change) % 2 == 1) {
                t = ((t / change) + 1) * change;
            }

            t += time;
            for (int j : conns[i]) {
                if (pass[j] < t && cnt[j] < 2) {
                    pass[j] = t;
                    q.emplace(t, j);
                    ++cnt[j];
                }
            }
        }

        return -1;
    }
};

TEST(&Solution::secondMinimum)