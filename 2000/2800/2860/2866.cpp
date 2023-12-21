/*
 * @Author: sanjusss
 * @Date: 2023-12-21 10:32:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-21 12:53:06
 * @FilePath: \2000\2800\2860\2866.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> lefts(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && maxHeights[s.top()] >= maxHeights[i]) {
                s.pop();
            }

            long long pre = s.empty() ? 0ll : lefts[s.top()];
            long long cnt = s.empty() ? i + 1 : i - s.top();
            lefts[i] = pre + cnt * maxHeights[i];
            s.push(i);
        }

        s = {};
        vector<long long> rights(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && maxHeights[s.top()] >= maxHeights[i]) {
                s.pop();
            }

            long long pre = s.empty() ? 0ll : rights[s.top()];
            long long cnt = s.empty() ? n - i: s.top() - i;
            rights[i] = pre + cnt * maxHeights[i];
            s.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, lefts[i] + rights[i] - maxHeights[i]);
        }

        return ans;
    }
};