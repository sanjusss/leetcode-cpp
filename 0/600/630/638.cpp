/*
 * @Author: sanjusss
 * @Date: 2021-10-24 11:48:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-24 15:22:46
 * @FilePath: \0\600\630\638.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans = INT_MAX;
        int n = price.size();
        int cost = 0;
        function<void(void)> dfs = [&]() {
            bool hasRun = false;
            for (auto& s : special) {
                bool success = true;
                for (int j = 0; j < n; ++j) {
                    if (needs[j] < s[j]) {
                        success = false;
                    }
                }

                if (!success) {
                    continue;
                }

                hasRun = true;
                for (int j = 0; j < n; ++j) {
                    needs[j] -= s[j];
                }

                cost += s[n];
                dfs();
                cost -= s[n];
                for (int j = 0; j < n; ++j) {
                    needs[j] += s[j];
                }
            }

            if (!hasRun) {
                int sum = 0;
                for (int i = 0; i < n; ++i) {
                    sum += needs[i] * price[i];
                }

                ans = min(ans, cost + sum);
            }
        };

        int scur = 0;
        for (int i = 0; i < special.size(); ++i) {
            bool success = true;
            int maxSum = 0;
            auto& s = special[i];
            for (int j = 0; j < n; ++j) {
                if (needs[j] < s[j]) {
                    success = false;
                    break;
                }
                else {
                    maxSum += s[j] * price[j];
                }
            }

            if (success && s[n] < maxSum) {
                if (scur != i) {
                    special[scur++] = move(s);
                }
                else {
                    ++scur;
                }
            }
        }

        special.resize(scur);
        dfs();
        return ans;
    }
};

TEST(&Solution::shoppingOffers)