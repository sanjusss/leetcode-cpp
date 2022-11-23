/*
 * @Author: sanjusss
 * @Date: 2022-11-23 08:47:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-23 08:49:37
 * @FilePath: \1000\1700\1740\1742.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> cnt;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int n = i;
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }

            ++cnt[sum];
        }

        int ans = 0;
        for (auto [_, c] : cnt) {
            ans = max(ans, c);
        }

        return ans;
    }
};