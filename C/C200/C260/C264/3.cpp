/*
 * @Author: sanjusss
 * @Date: 2021-10-24 10:49:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-24 11:03:16
 * @FilePath: \C\C200\C260\C264\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int64_t>> childrenCount(n);
        vector<int> ins(n);
        for (int i = 1; i < n; ++i) {
            ++ins[parents[i]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (ins[i] == 0) {
                q.push(i);
            }
        }

        int ans = 0;
        int64_t maxMul = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int64_t mul = 1;
            int totalChildren = 0;
            for (int j : childrenCount[i]) {
                totalChildren += j;
                mul *= j;
            }

            int parentCount = n - 1 - totalChildren;
            if (parentCount > 0) {
                mul *= parentCount;
            }

            if (mul == maxMul) {
                ++ans;
            }
            else if (mul > maxMul) {
                maxMul = mul;
                ans = 1;
            }

            int parent = parents[i];
            if (parent >= 0) {
                childrenCount[parent].push_back(totalChildren + 1);
                if (--ins[parent] == 0) {
                    q.push(parent);
                }
            }
        }

        return ans;
    }
};