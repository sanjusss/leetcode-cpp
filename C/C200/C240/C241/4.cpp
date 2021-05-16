/*
 * @Author: sanjusss
 * @Date: 2021-05-16 10:27:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-16 12:45:42
 * @FilePath: \C\C200\C240\C241\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        static const int mod = 1e9 + 7;
        vector<int> cur(k + 1);
        vector<int> prev(k + 1);
        cur[0] = 1;
        for (int64_t i = 0; i < n; ++i) {
            swap(cur, prev);
            cur[0] = 0;
            for (int j = 1; j <= k; ++j) {
                cur[j] = (prev[j - 1] + i * prev[j] % mod) % mod;
            }
        }

        return cur[k];
    }
};

TEST(&Solution::rearrangeSticks)