#pragma once
#include "leetcode.h"

class Solution {
public:
    int minDays(int n) {
        unordered_set<int> passed;
        queue<int> q;
        int ans = 0;
        q.push(n);
        passed.insert(n);
        int cur;
        int next;
        while (true) {
            for (int i = q.size() - 1; i >= 0; --i) {
                cur = q.front();
                q.pop();
                if (cur == 0) {
                    return ans;
                }

                if (cur % 3 == 0) {
                    next = cur / 3;
                    if (passed.find(next) == passed.end()) {
                        q.push(next);
                        passed.insert(next);
                    }
                }

                if (cur % 2 == 0) {
                    next = cur / 2;
                    if (passed.find(next) == passed.end()) {
                        q.push(next);
                        passed.insert(next);
                    }
                }

                next = cur - 1;
                if (passed.find(next) == passed.end()) {
                    q.push(next);
                    passed.insert(next);
                }
            }

            ++ans;
        }

        return ans;
    }
};