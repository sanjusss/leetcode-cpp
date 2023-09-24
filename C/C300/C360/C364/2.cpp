/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-24 10:40:13
 * @FilePath: \C\C300\C360\C364\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        int n = maxHeights.size();
        for (int i = 0; i < n; ++i) {
            long long sum = maxHeights[i];
            int cur = maxHeights[i];
            for (int j = i - 1; j >= 0; --j) {
                cur = min(maxHeights[j], cur);
                sum += cur;
            }

            cur = maxHeights[i];
            for (int j = i + 1; j < n; ++j) {
                cur = min(maxHeights[j], cur);
                sum += cur;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};