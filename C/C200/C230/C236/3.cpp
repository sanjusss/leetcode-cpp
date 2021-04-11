/*
 * @Author: sanjusss
 * @Date: 2021-04-11 10:38:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-11 10:52:41
 * @FilePath: \C\C200\C230\C236\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        array<int, 3> dp = { 1, 0, 1 };
        array<int, 3> temp;
        for (int i = 1; i < obstacles.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                if (j + 1 == obstacles[i]) {
                    temp[j] = INT_MAX / 2;
                }
                else {
                    temp[j] = dp[j];
                    for (int k = 0; k < 3; ++k) {
                        if (j != k && k + 1 != obstacles[i]) {
                            temp[j] = min(temp[j], dp[k] + 1);
                        }
                    }
                }
            }

            swap(temp, dp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};

TEST(&Solution::minSideJumps)