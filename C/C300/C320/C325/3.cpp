/*
 * @Author: sanjusss
 * @Date: 2022-12-25 10:25:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-25 11:11:19
 * @FilePath: \C\C300\C320\C325\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int left = 0;
        int right = price.back() - price.front();
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int cnt = 1;
            int i = 0;
            int v = price[0];
            while (cnt < k) {
                v += mid;
                ++i;
                auto p = lower_bound(price.begin() + i, price.end(), v);
                if (p == price.end()) {
                    break;
                }

                i = p - price.begin();
                v = *p;
                ++cnt;
            }

            if (cnt == k) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};