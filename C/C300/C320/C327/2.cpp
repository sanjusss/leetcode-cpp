/*
 * @Author: sanjusss
 * @Date: 2023-01-08 10:25:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-08 10:34:12
 * @FilePath: \C\C300\C320\C327\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int64_t ans = 0;
        priority_queue<int> q;
        for (int i : nums) {
            q.push(i);
        }

        for (int i = 0; i < k; ++i) {
            int v = q.top();
            q.pop();
            ans += v;
            q.push((v + 3 - 1) / 3);
        }

        return ans;
    }
};