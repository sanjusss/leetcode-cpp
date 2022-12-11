/*
 * @Author: sanjusss
 * @Date: 2022-12-11 10:07:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-11 10:13:48
 * @FilePath: \1000\1600\1690\1691.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& c : cuboids) {
            sort(c.begin(), c.end());
        }

        sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] + a[2] > b[0] + b[1] + b[2];
        });

        int n = cuboids.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            auto& a = cuboids[i];
            dp[i] = a[2];
            for (int j = 0; j < i; ++j) {
                auto& b = cuboids[j];
                if (a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2]) {
                    dp[i] = max(dp[i], dp[j] + a[2]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};