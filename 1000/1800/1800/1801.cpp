/*
 * @Author: sanjusss
 * @Date: 2023-01-02 16:04:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-02 16:18:34
 * @FilePath: \1000\1800\1800\1801.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> q2buy;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q2sell;
        for (auto& o : orders) {
            int price = o[0];
            int amount = o[1];
            if (o[2] == 0) { 
                // 采购
                while (amount > 0 && !q2sell.empty() && price >= q2sell.top().first) {
                    auto [p, a] = q2sell.top();
                    q2sell.pop();
                    int use = min(a, amount);
                    amount -= use;
                    a -= use;
                    if (a > 0) {
                        q2sell.emplace(p, a);
                    }
                }

                if (amount > 0) {
                    q2buy.emplace(price, amount);
                }
            }
            else {
                // 销售
                while (amount > 0 && !q2buy.empty() && price <= q2buy.top().first) {
                    auto [p, a] = q2buy.top();
                    q2buy.pop();
                    int use = min(a, amount);
                    amount -= use;
                    a -= use;
                    if (a > 0) {
                        q2buy.emplace(p, a);
                    }
                }

                if (amount > 0) {
                    q2sell.emplace(price, amount);
                }
            }
        }

        static constexpr int64_t mod = 1e9 + 7;
        int64_t ans = 0;
        while (!q2sell.empty()) {
            ans += q2sell.top().second;
            ans %= mod;
            q2sell.pop();
        }
        while (!q2buy.empty()) {
            ans += q2buy.top().second;
            ans %= mod;
            q2buy.pop();
        }

        return ans;
    }
};