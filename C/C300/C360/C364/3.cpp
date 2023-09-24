/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-24 10:50:27
 * @FilePath: \C\C300\C360\C364\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        stack<int> s;
        vector<int64_t> lefts(n);
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && maxHeights[s.top()] > maxHeights[i]) {
                s.pop();
            }

            if (s.empty()) {
                lefts[i] = (int64_t)maxHeights[i] * (i + 1);
            }
            else {
                lefts[i] = lefts[s.top()] + (int64_t)maxHeights[i] * (i - s.top());
            }

            s.push(i);
        }

        s = stack<int>();
        vector<int64_t> rights(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && maxHeights[s.top()] > maxHeights[i]) {
                s.pop();
            }

            if (s.empty()) {
                rights[i] = (int64_t)maxHeights[i] * (n - i);
            }
            else {
                rights[i] = rights[s.top()] + (int64_t)maxHeights[i] * (s.top() - i);
            }

            s.push(i);
        }

        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, lefts[i] + rights[i] - maxHeights[i]);
        }

        return ans;
    }
};