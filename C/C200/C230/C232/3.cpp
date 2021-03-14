/*
 * @Author: sanjusss
 * @Date: 2021-03-14 10:44:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-14 11:06:17
 * @FilePath: \C\C200\C230\C232\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double sum = 0;
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return (((double)(a.first + 1) / (double)(a.second + 1)) - ((double)a.first / (double)a.second)) <
                   (((double)(b.first + 1) / (double)(b.second + 1)) - ((double)b.first / (double)b.second));
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (auto& c : classes) {
            if (c[0] == c[1]) {
                sum += 1;
            }
            else {
                q.emplace(c[0], c[1]);
            }
        }

        if (q.empty()) {
            return 1;
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto p = q.top();
            q.pop();
            ++p.first;
            ++p.second;
            q.push(p);
        }

        while (!q.empty()) {
            auto [p, t] = q.top();
            sum += (double)p / (double)t;
            q.pop();
        }

        return sum / classes.size();
    }
};

TEST(&Solution::maxAverageRatio)