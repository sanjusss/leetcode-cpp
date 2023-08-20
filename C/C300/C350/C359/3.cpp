/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-20 10:51:20
 * @FilePath: \C\C300\C350\C359\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int ans = 0;
        vector<pair<int, int>> pres;
        pres.emplace_back(-1, 0);
        for (auto& o : offers) {
            int b = o[0];
            int e = o[1];
            int g = o[2];
            auto p = lower_bound(pres.begin(), pres.end(), b, [](const pair<int, int>& a, int v) {
                return a.first < v;
            });
            g += prev(p)->second;
            ans = max(ans, g);
            if (pres.back().first == e) {
                if (pres.back().second < g) {
                    pres.pop_back();
                }
                else {
                    continue;
                }
            }

            if (pres.back().second >= g) {
                continue;
            }

            pres.emplace_back(e, g);
        }

        return ans;
    }
};