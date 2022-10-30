/*
 * @Author: sanjusss
 * @Date: 2022-10-30 10:46:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-30 11:01:05
 * @FilePath: \C\C300\C310\C317\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        vector<int> bits;
        while (n > 0) {
            bits.push_back(n % 10);
            n /= 10;
        }

        bits.push_back(0);
        if (accumulate(bits.begin(), bits.end(), 0) <= target) {
            return 0;
        }

        for (int i = 1; ; ++i) {
            if (bits[i] == 9 || accumulate(bits.begin() + i, bits.end(), 1) > target) {
                continue;
            }

            int64_t ans = 1;
            int64_t sub = 0;
            for (int j = i - 1; j >= 0; --j) {
                ans *= 10;
                sub = sub * 10 + bits[j];
            }

            return ans - sub;
        }

        return 0;
    }
};