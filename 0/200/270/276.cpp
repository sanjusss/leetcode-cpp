/*
 * @Author: sanjusss
 * @Date: 2022-06-24 08:50:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-24 09:06:47
 * @FilePath: \0\200\270\276.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numWays(int n, int k) {
        int all = 2 * k;
        vector<int> cur(all);
        vector<int> pre(all);
        fill(cur.begin(), cur.begin() + k, 1);
        int sum = k;
        for (int i = 2; i <= n; ++i) {
            swap(cur, pre);
            for (int j = 0; j < k; ++j) {
                // 不连续
                cur[j] = sum - pre[j] - pre[j + k];
                // 连续两个
                cur[j + k] = pre[j];
            }
            
            sum = accumulate(cur.begin(), cur.end(), 0);
        }

        return sum;
    }
};

TEST(&Solution::numWays)