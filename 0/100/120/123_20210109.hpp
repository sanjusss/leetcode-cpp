/*
 * @Author: sanjusss
 * @Date: 2021-01-09 10:56:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-09 11:27:55
 * @FilePath: \0\100\120\123_20210109.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if (n < 2) {
//             return 0;
//         }

//         static const int maxSell = 2;
//         vector<vector<int>> hold(n, vector<int>(maxSell + 1, INT_MIN / 2));
//         vector<vector<int>> empty(n, vector<int>(maxSell + 1));
//         hold[0][0] = -prices[0];
//         for (int i = 1; i < n; ++i) {
//             hold[i][0] = max(hold[i - 1][0], -prices[i]);
//             for (int j = 1; j <= maxSell; ++j) {
//                 hold[i][j] = max(hold[i - 1][j], empty[i - 1][j] - prices[i]);
//                 empty[i][j] = max(empty[i - 1][j], hold[i - 1][j - 1] + prices[i]);
//             }
//         }

//         return *max_element(empty[n - 1].begin(), empty[n - 1].end());
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if (n < 2) {
//             return 0;
//         }

//         static const int maxSell = 2;
//         vector<int> hold(maxSell + 1, INT_MIN / 2);
//         vector<int> empty(maxSell + 1);
//         hold[0] = -prices[0];
//         for (int i = 1; i < n; ++i) {
//             hold[0] = max(hold[0], -prices[i]);
//             for (int j = 1; j <= maxSell; ++j) {
//                 tie(hold[j], empty[j]) = make_pair(max(hold[j], empty[j] - prices[i]), max(empty[j], hold[j - 1] + prices[i]));
//             }
//         }

//         return *max_element(empty.begin(), empty.end());
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }

        int hold1 = -prices[0];
        int empty1 = 0;
        int hold2 = -prices[0];
        int empty2 = 0;
        for (int i = 1; i < n; ++i) {
            empty2 = max(empty2, hold2 + prices[i]);
            hold2 = max(hold2, empty1 - prices[i]);
            empty1 = max(empty1, hold1 + prices[i]);
            hold1 = max(hold1, -prices[i]);
        }

        return empty2;
    }
};