/*
 * @Author: sanjusss
 * @Date: 2021-09-08 08:32:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-08 08:57:21
 * @FilePath: \0\500\500\502.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        k = min(k, n);
        priority_queue<int> qpro;
        auto cmpCap = [&profits, &capital] (int a, int b) {
            if (capital[a] == capital[b]) {
                return profits[a] < profits[b];
            }
            else {
                return capital[a] > capital[b];
            }
        };
        priority_queue<int, vector<int>, decltype(cmpCap)> qcap(cmpCap);
        for (int i = 0; i < n; ++i) {
            if (capital[i] <= w) {
                qpro.push(profits[i]);
            }
            else {
                qcap.push(i);
            }
        }

        int ans = w;
        while (k > 0) {
            --k;
            while (!qcap.empty() && capital[qcap.top()] <= ans) {
                qpro.push(profits[qcap.top()]);
                qcap.pop();
            }

            if (qpro.empty()) {
                break;
            }
            else {
                ans += qpro.top();
                qpro.pop();
            }
        }

        return ans;
    }
};

TEST(&Solution::findMaximizedCapital)