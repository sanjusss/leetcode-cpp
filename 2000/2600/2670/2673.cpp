/*
 * @Author: sanjusss
 * @Date: 2024-02-28 09:21:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-02-28 12:05:48
 * @FilePath: \2000\2600\2670\2673.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<int> sum(n);
        sum[0] = cost[0];
        for (int i = 0; (i + 1) * 2 < n; ++i) {
            sum[(i + 1) * 2 - 1] = sum[i] + cost[(i + 1) * 2 - 1];
            sum[(i + 1) * 2] = sum[i] + cost[(i + 1) * 2];
        }

        vector<int> maxsum = sum;
        for (int i = n - 1; i > 0; --i) {
            maxsum[(i + 1) / 2 - 1] = max(maxsum[i], maxsum[(i + 1) / 2 - 1]);
        }

        int target = maxsum[0];
        int ans = 0;
        vector<int> diff(n);
        for (int i = 1; i < n; ++i) {
            int add = target - (diff[i] + maxsum[i]);
            diff[i] += add;
            ans += add;
            if ((i + 1) * 2 < n) {
                diff[(i + 1) * 2 - 1] = diff[i];
                diff[(i + 1) * 2] = diff[i];
            }
        }

        return ans;
    }
};