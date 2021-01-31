/*
 * @Author: sanjusss
 * @Date: 2021-01-31 10:35:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-31 10:40:18
 * @FilePath: \C\C200\C220\C226\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> cnt(100);
        for (int i = lowLimit; i <= highLimit; ++i) {
            int n = i;
            int c = 0;
            while (n > 0) {
                c += n % 10;
                n /= 10;
            }

            ++cnt[c];
        }

        return *max_element(cnt.begin(), cnt.end());
    }
};