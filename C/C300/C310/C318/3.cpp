/*
 * @Author: sanjusss
 * @Date: 2022-11-06 10:41:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-06 10:50:02
 * @FilePath: \C\C300\C310\C318\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int left = 0;
        int right = costs.size() - 1;
        auto cmp = [&costs](int a, int b) {
            if (costs[a] == costs[b]) {
                return a > b;
            }
            else {
                return costs[a] > costs[b];
            }
        };
        priority_queue<int, vector<int>, decltype(cmp)> qfront(cmp);
        priority_queue<int, vector<int>, decltype(cmp)> qback(cmp);

        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            while (left <= right && qfront.size() < candidates) {
                qfront.push(left++);
            }

            while (left <= right && qback.size() < candidates) {
                qback.push(right--);
            }

            if (qback.empty()) {
                ans += costs[qfront.top()];
                qfront.pop();
            }
            else if (qfront.empty()) {
                ans += costs[qback.top()];
                qback.pop();
            }
            else if (cmp(qfront.top(), qback.top())) {
                ans += costs[qback.top()];
                qback.pop();
            }
            else {
                ans += costs[qfront.top()];
                qfront.pop();
            }
        }

        return ans;
    }
};