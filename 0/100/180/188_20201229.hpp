/*
 * @Author: sanjusss
 * @Date: 2020-12-29 20:57:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-30 17:23:38
 * @FilePath: \0\100\180\188_20201229.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         if (n <= 1) {
//             return 0;
//         }

//         k = min(k, n / 2);
//         vector<vector<int>> hold(n, vector<int>(k + 1));
//         vector<vector<int>> empty(n, vector<int>(k + 1));
//         hold[0][0] = -prices[0];
//         for (int j = 1; j <= k; ++j) {
//             hold[0][j] = INT_MIN / 2;
//             empty[0][j] = INT_MIN / 2;
//         }

//         for (int i = 1; i < n; ++i) {
//             hold[i][0] = max(-prices[i], hold[i - 1][0]);
//             for (int j = 1; j <= k; ++j) {
//                 hold[i][j] = max(empty[i - 1][j] - prices[i], hold[i - 1][j]);
//                 empty[i][j] = max(hold[i - 1][j - 1] + prices[i], empty[i - 1][j]);
//             }
//         }

//         return *max_element(empty[n - 1].begin(), empty[n - 1].end());
//     }
// };

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }

        k = min(k, n / 2);
        vector<int> hold(k + 1, INT_MIN / 2);
        vector<int> empty(k + 1, INT_MIN / 2);
        hold[0] = -prices[0];
        empty[0] = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                tie(hold[j], empty[j]) =
                    make_tuple(max(empty[j] - prices[i], hold[j]), max(hold[j - 1] + prices[i], empty[j]));
            }

            hold[0] = max(-prices[i], hold[0]);
        }

        return *max_element(empty.begin(), empty.end());
    }
};