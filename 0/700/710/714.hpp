#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         vector<vector<int>> singles(n, vector<int>(n));
//         for (int i = 0; i < n; ++i) {
//             int buy = prices[i];
//             for (int j = i + 1; j < n; ++j) {
//                 if (prices[j] < buy) {
//                     singles[i][j] = singles[i][j - 1];
//                     buy = prices[j];
//                 }
//                 else {
//                     singles[i][j] = max(singles[i][j - 1], prices[j] - buy - fee);
//                 }
//             }
//         }

//         vector<vector<int>> profits(n, vector<int>(n));
//         for (int i = n - 1; i >= 0; --i) {
//             for (int j = i + 1; j < n; ++j) {
//                 profits[i][j] = singles[i][j];
//                 for (int k = j - i; k > 0; --k) {
//                     profits[i][j] = max(profits[i][j], singles[i][i + k - 1] + profits[i + k][j]);
//                 }
//             }
//         }

//         return profits[0][n - 1];
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         vector<int> profits(n);
//         int minIndex = 0;
//         for (int i = 1; i < n; ++i) {
//             if (prices[i] < prices[i - 1]) {
//                 profits[i] = profits[i - 1];
//                 if (profits[i] - profits[minIndex] >= prices[i] - prices[minIndex]) {
//                     minIndex = i;
//                 }
//             }
//             else {
//                 profits[i] = max(profits[minIndex] + max(0, prices[i] - prices[minIndex] - fee), profits[i - 1]);
//             }
//         }

//         return profits[n - 1];
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         int ans = 0;
//         int buy = 0;
//         int buyIndex = 0;
//         for (int i = 1; i < n; ++i) {
//             if (prices[i] < prices[i - 1]) {
//                 if (ans - buy >= prices[i] - prices[buyIndex]) {
//                     buyIndex = i;
//                     buy = ans;
//                 }
//             }
//             else {
//                 ans = max(buy + max(0, prices[i] - prices[buyIndex] - fee), ans);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0];
        int empty = 0;
        for (int i = 1; i < prices.size(); ++i) {
            tie(hold, empty) = make_tuple(max(hold, empty - prices[i]), max(hold + prices[i] - fee, empty));
        }

        return empty;
    }
};