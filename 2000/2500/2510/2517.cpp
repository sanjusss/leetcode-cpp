/*
 * @Author: sanjusss
 * @Date: 2023-06-01 10:13:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-01 10:19:32
 * @FilePath: \2000\2500\2510\2517.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int left = 0;
        int right = price[n - 1] - price[0];
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int cnt = 1;
            int prev = 0;
            for (int i = 1; i < n; ++i) {
                if (price[i] >= price[prev] + mid) {
                    prev = i;
                    ++cnt;
                }
            }

            if (cnt < k) {
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }

        return left;
    }
};

TEST(&Solution::maximumTastiness)