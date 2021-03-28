/*
 * @Author: sanjusss
 * @Date: 2021-03-21 10:38:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-21 10:56:00
 * @FilePath: \C\C200\C230\C234\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        static const int mod = 1e9 + 7;
        auto cmpSamll = [&orders](int a, int b) {
            return orders[a][0] < orders[b][0];
        };
        auto cmpGreat = [&orders](int a, int b) {
            return orders[a][0] > orders[b][0];
        };
        priority_queue<int, vector<int>, decltype(cmpGreat)> sell(cmpGreat);
        priority_queue<int, vector<int>, decltype(cmpSamll)> buy(cmpSamll);
        int n = orders.size();
        for (int i = 0; i < n; ++i) {
            auto& cur = orders[i];
            if (cur[2] == 0) {//buy
                while (cur[1] > 0 && !sell.empty() && orders[sell.top()][0] <= cur[0]) {
                    if (orders[sell.top()][1] > cur[1]) {
                        orders[sell.top()][1] -= cur[1];
                        cur[1] = 0;
                    }
                    else {
                        cur[1] -= orders[sell.top()][1];
                        sell.pop();
                    }
                }

                if (cur[1] > 0) {
                    buy.push(i);
                }
            }
            else {//sell
                while (cur[1] > 0 && !buy.empty() && orders[buy.top()][0] >= cur[0]) {
                    if (orders[buy.top()][1] > cur[1]) {
                        orders[buy.top()][1] -= cur[1];
                        cur[1] = 0;
                    }
                    else {
                        cur[1] -= orders[buy.top()][1];
                        buy.pop();
                    }
                }

                if (cur[1] > 0) {
                    sell.push(i);
                }
            }
        }

        int ans = 0;
        while (!sell.empty()) {
            int i = sell.top();
            sell.pop();
            ans = (ans + orders[i][1]) % mod;
        }

        while (!buy.empty()) {
            int i = buy.top();
            buy.pop();
            ans = (ans + orders[i][1]) % mod;
        }

        return ans;
    }
};

TEST(&Solution::getNumberOfBacklogOrders)