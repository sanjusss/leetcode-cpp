/*
 * @Author: sanjusss
 * @Date: 2021-12-22 21:22:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-22 21:26:04
 * @FilePath: \0\600\680\686.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (b.empty()) {
            return 0;
        }

        int ans = INT_MAX;
        int n = a.size();
        int m = b.size();
        for (int i = 0; i < n; ++i) {
            int j = 0;
            int k = 0;
            while (j < m && a[(i + k) % n] == b[j]) {
                ++j;
                ++k;
            }

            if (j == m) {
                ans = min(ans, (i + k + n - 1) / n);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};