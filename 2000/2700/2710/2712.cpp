/*
 * @Author: sanjusss
 * @Date: 2023-05-29 10:30:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-29 10:50:48
 * @FilePath: \2000\2700\2710\2712.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long minimumCost(string s) {
        int64_t ans = 0;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                continue;
            }

            ans += min(i, n - i);
        }

        return ans;
    }
};