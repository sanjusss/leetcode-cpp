/*
 * @Author: sanjusss
 * @Date: 2022-09-01 08:37:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-01 08:44:28
 * @FilePath: \1000\1400\1470\1475_20220901.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && s.top() > prices[i]) {
                s.pop();
            }

            if (s.empty()) {
                ans[i] = prices[i];
                s.push(prices[i]);
            }
            else {
                ans[i] = prices[i] - s.top();
                if (s.top() != prices[i]) {
                    s.push(prices[i]);
                }
            }
        }

        return ans;
    }
};