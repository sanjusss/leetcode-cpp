/*
 * @Author: sanjusss
 * @Date: 2023-03-30 08:40:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-30 08:44:00
 * @FilePath: \1000\1600\1640\1641.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> cur(5);
        cur[0] = 1;
        vector<int> pre(5);
        for (int i = 1; i <= n; ++i) {
            swap(pre, cur);
            for (int j = 0; j < 5; ++j) {
                cur[j] = 0;
                for (int k = 0; k <= j; ++k) {
                    cur[j] += pre[k];
                }
            }
        }

        return accumulate(cur.begin(), cur.end(), 0);
    }
};