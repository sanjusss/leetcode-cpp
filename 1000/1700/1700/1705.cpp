/*
 * @Author: sanjusss
 * @Date: 2021-12-24 09:38:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-24 09:48:15
 * @FilePath: \1000\1700\1700\1705.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        int ans = 0;
        for (int i = 0; i < n || !q.empty(); ++i) {
            if (i < n && apples[i] > 0) {
                q.emplace(i + days[i], apples[i]);
            }

            while (!q.empty() && q.top().first <= i) {
                q.pop();
            }

            if (!q.empty()) {
                ++ans;
                auto [d, c] = q.top();
                q.pop();
                if (c > 1) {
                    q.emplace(d, c - 1);
                }
            }
        }

        return ans;
    }
};