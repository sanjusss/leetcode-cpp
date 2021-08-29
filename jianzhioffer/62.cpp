/*
 * @Author: sanjusss
 * @Date: 2021-08-29 09:27:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-29 09:35:45
 * @FilePath: \jianzhioffer\62.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = (ans + m) % i;
        }

        return ans;
    }
};