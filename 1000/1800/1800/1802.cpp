/*
 * @Author: sanjusss
 * @Date: 2023-01-04 08:36:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-04 08:52:58
 * @FilePath: \1000\1800\1800\1802.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int64_t left = 1;
        int64_t right = maxSum;
        while (left < right) {
            int64_t mid = (left + right + 1) / 2;
            int64_t sum = mid;
            if (mid > index) {
                sum += (mid - 1 + mid - index) * index / 2;
            }
            else {
                sum += (mid - 1 + 1) * (mid - 1) / 2 + index - (mid - 1);
            }

            if (mid > n - 1 - index) {
                sum += (mid - 1 + mid - (n - 1 - index)) * (n - 1 - index) / 2;
            }
            else {
                sum += (mid - 1 + 1) * (mid - 1) / 2 + (n - 1 - index) - (mid - 1);
            }

            if (sum > maxSum) {
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }

        return left;
    }
};