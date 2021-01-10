#pragma once
#include "leetcode.h"

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end());
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < k; ++i) {
            q.push(jobs.back());
            jobs.pop_back();
        }

        while (!jobs.empty()) {
            q.push(q.top() + jobs.back());
            q.pop();
            jobs.pop_back();
        }

        while (q.size() > 1) {
            q.pop();
        }

        return q.top();
    }
};