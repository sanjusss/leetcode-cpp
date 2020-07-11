#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int maxProfit(int k, vector<int>& prices) {
//        if (k <= 0) {
//            return 0;
//        }
//
//        int n = prices.size();
//        int maxSell = min(k, n / 2);
//        vector<int> states(maxSell * 2 + 1, INT_MIN);
//        states[0] = 0;
//        int jStart;
//        for (int i = 0; i < prices.size(); ++i) {
//            if (i / 2 < maxSell) {
//                jStart = (i / 2) * 2 + 2;
//            }
//            else {
//                jStart = maxSell * 2;
//            }
//
//            for (int j = jStart; j > 0; j -= 2) {
//                states[j] = max(states[j], states[j - 1] + prices[i]);
//                states[j - 1] = max(states[j - 1], states[j - 2] - prices[i]);
//            }
//        }
//
//        return *max_element(states.begin(), states.end());
//    }
//};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0) {
            return 0;
        }

        int n = prices.size();
        if (n / 2 <= k) {
            return maxProfit(prices);
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2)));
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 1; --j) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[0];
                }
                else {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }

        return dp[n - 1][k][0];
    }

private:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int none = 0;
        int prevNone;
        for (int i : prices) {
            prevNone = none;
            none = max(none, hold + i);
            hold = max(hold, prevNone - i);
        }

        return none;
    }
};