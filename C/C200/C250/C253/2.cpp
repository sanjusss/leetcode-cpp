/*
 * @Author: sanjusss
 * @Date: 2021-08-08 10:29:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-08 10:36:39
 * @FilePath: \C\C200\C250\C253\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for (int i : piles) {
            q.push(i);
        }

        while (q.top() > 0 && k > 0) {
            --k;
            int i = q.top();
            q.pop();
            q.push((i + 1) / 2);
        }

        int ans = 0;
        while (!q.empty()) {
            ans += q.top();
            q.pop();
        }

        return ans;
    }
};