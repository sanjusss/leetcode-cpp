/*
 * @Author: sanjusss
 * @Date: 2022-01-23 10:28:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-23 10:56:04
 * @FilePath: \C\C200\C270\C277\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        for (int mask = (1 << n) - 1; mask > 0; --mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt <= ans) {
                continue;
            }

            bool success = true;
            for (int i = 0; i < n && success; ++i) {
                if (!((1 << i) & mask)) {
                    continue;
                }

                for (int j = 0; j < n; ++j) {
                    if (statements[i][j] == 0) {
                        if ((1 << j) & mask) {
                            success = false;
                            break;
                        }
                    }
                    else if (statements[i][j] == 1) {
                        if (!((1 << j) & mask)) {
                            success = false;
                            break;
                        }
                    }
                }
            }

            if (success) {
                ans = cnt;
            }
        }

        return ans;
    }
};

TEST(&Solution::maximumGood)