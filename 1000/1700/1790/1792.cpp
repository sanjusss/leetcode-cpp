/*
 * @Author: sanjusss
 * @Date: 2023-02-19 10:08:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-19 12:08:48
 * @FilePath: \1000\1700\1790\1792.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int full = 0;
        auto eff = [] (double a, double b) {
            return (a + 1) / (b + 1) - a / b;
        };
        priority_queue<tuple<double, int, int>> q;
        for (auto& c : classes) {
            if (c[0] == c[1]) {
                ++full;
            }
            else {
                q.emplace(eff(c[0], c[1]), c[0], c[1]);
            }
        }

        while (!q.empty() && extraStudents-- > 0) {
            auto [_, a, b] = q.top();
            q.pop();
            ++a;
            ++b;
            q.emplace(eff(a, b), a, b);
        }

        double sum = full;
        while (!q.empty()) {
            auto [_, a, b] = q.top();
            q.pop();
            sum += (double)a / (double)b;
        }

        return sum / classes.size();
    }
};

TEST(&Solution::maxAverageRatio)