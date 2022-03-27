/*
 * @Author: sanjusss
 * @Date: 2022-03-27 10:27:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-27 11:51:24
 * @FilePath: \C\C200\C280\C286\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1);
        vector<int> temp(k + 1);
        for (auto& p : piles) {
            int n = p.size();
            for (int i = 1; i < n; ++i) {
                p[i] += p[i - 1];
            }

            for (int i = 1; i <= k; ++i) {
                temp[i] = dp[i];
                for (int j = min(n, i); j > 0; --j) {
                    temp[i] = max(temp[i], dp[i - j] + p[j - 1]);
                }
            }

            swap(temp, dp);
        }

        return dp[k];
    }
};

TEST(&Solution::maxValueOfCoins)