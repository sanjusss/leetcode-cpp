/*
 * @Author: sanjusss
 * @Date: 2022-09-24 15:24:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-24 15:31:30
 * @FilePath: \LCP\20220924\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        auto cmp = [](int a, int b) {
            if (a == b) {
                return 0;
            }
            else if (a > b) {
                return 1;
            }
            else {
                return -1;
            }
        };
        int n = temperatureA.size();
        vector<int> trA;
        vector<int> trB;
        for (int i = 1; i < n; ++i) {
            trA.push_back(cmp(temperatureA[i], temperatureA[i - 1]));
            trB.push_back(cmp(temperatureB[i], temperatureB[i - 1]));
        }

        int ans = 0;
        int m = trA.size();
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            while (i < m && trA[i] == trB[i]) {
                ++cnt;
                ++i;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};