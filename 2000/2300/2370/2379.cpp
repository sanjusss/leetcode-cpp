/*
 * @Author: sanjusss
 * @Date: 2023-03-09 08:38:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-09 08:45:00
 * @FilePath: \2000\2300\2370\2379.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w = 0;
        int ans = INT_MAX;
        int n = blocks.size();
        for (int i = 0; i < n; ++i) {
            if (blocks[i] == 'W') {
                ++w;
            }

            if (i < k - 1) {
                continue;
            }

            ans = min(w, ans);
            if (blocks[i - k + 1] == 'W') {
                --w;
            }
        }

        return ans;
    }
};

TEST(&Solution::minimumRecolors)